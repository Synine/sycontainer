#!/usr/bin/python3

import os, subprocess, shutil, json

MESON_EXECUTABLE = "meson"

MESON_SETUP = "setup"
MESON_DIST = "dist"

BUILDDIR = "_build"
MESON_DISTDIR = "meson-dist"
MESON_INFODIR = "meson-info"
MESON_INFOFILE = "meson-info.json"

RPMBUILD_DIRECTORY = os.path.join(os.environ["HOME"], "rpmbuild")
SPEC_DIR = os.path.join(RPMBUILD_DIRECTORY, "SPECS")
SOURCE_DIR = os.path.join(RPMBUILD_DIRECTORY, "SOURCES")

def generate_rpmspec_name(filename: str, version: str, release: int):
    return filename + "-" + version + "-" + str(release) + ".spec"

def generate_generic_tarball_name(filename: str, version: str):
    return filename + "-" + version + ".tar.xz"

def generate_rpmtarball_name(filename: str, version: str, release: int):
    return filename + "-" + version + "-" + str(release) + ".tar.xz"

if __name__ == "__main__":
    print(os.getcwd())
    full_builddir = os.path.join(os.getcwd(), BUILDDIR)
    if os.path.exists(full_builddir):
        shutil.rmtree(full_builddir)
    setup_result = subprocess.run([
        MESON_EXECUTABLE,
        MESON_SETUP,
        BUILDDIR
    ])
    if setup_result.returncode != 0:
        print("Error in Meson. Try again")
        exit(1)
    dist_result = subprocess.run([
        MESON_EXECUTABLE,
        MESON_DIST,
        "-C",
        BUILDDIR
    ], capture_output=True)
    if dist_result.returncode != 0:
        print("ERROR IN RUNNING DIST COMMAND")
        print(dist_result)
        exit(1)
    
    full_infofile = os.path.join(full_builddir, MESON_INFODIR, MESON_INFOFILE)
    with open(full_infofile, 'r') as infofile:
        info_vals = json.load(infofile)
        project_infopath = info_vals["introspection"]["information"]["projectinfo"]["file"]
        print(project_infopath)
        project_path = os.path.join(full_builddir, MESON_INFODIR, project_infopath)
        with open(project_path, 'r') as projectfile:
            projectinfo = json.load(projectfile)
            project_version = projectinfo["version"]
            project_name = projectinfo["descriptive_name"]
            source_tarballpath = os.path.join(os.getcwd(), BUILDDIR, MESON_DISTDIR, generate_generic_tarball_name(project_name, project_version))
            print(f"Tarball path: {source_tarballpath}")
            rpm_specfilepath = os.path.join(os.getcwd(), "dist", "rpm.spec")
            rpm_specname = ""
            selected = False
            while not selected:
                rel = int(input("Enter the release number for RPM: ").strip())
                print(f"Name: {project_name}")
                print(f"Version: {project_version}")
                print(f"Release: {rel}")
                rpm_specname = generate_rpmspec_name(project_name, project_version, rel)
                print(f"RPM Spec File: {rpm_specname}")
                rpm_sourcename = os.path.join(SOURCE_DIR, generate_rpmtarball_name(project_name, project_version, rel))
                print(f"RPM Source File: {rpm_sourcename}")
                if input("Are you sure?(y/N): ").strip().lower() == "y":
                    selected = True
                    continue
                if input("Do you want to cancel?(y/N): ").strip().lower() == "y":
                    exit(0)
            # COPY SOURCE FILE
            print(f"{source_tarballpath} -> {rpm_sourcename}")
            shutil.copy(source_tarballpath, rpm_sourcename)
            # COPY SOURCE SHASUM
            shutil.copy(source_tarballpath + ".sha256sum", rpm_sourcename + ".sha256sum")
            # COPY SPEC FILE
            shutil.copy(rpm_specfilepath, os.path.join(SPEC_DIR, rpm_specname))
            print(f"Tarball is copied to {rpm_sourcename}")
            print(f"SHA256SUM: {source_tarballpath + '.sha256sum'}")
            print(f"Specfile copied to {os.path.join(SPEC_DIR, rpm_specname)}")
            