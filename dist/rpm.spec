Name: sycontainer
Version: 1.0.0
Release: 1
Summary: C Library for a container that can hold multiple kinds of data.
License: MIT

Source0: %{name}-%{version}-%{release}.tar.xz

BuildRequires: meson
BuildRequires: gcc

%description

In cases where one needs to write data-structures where heterogenous data needs
to be saved, one can use this data-structure to implement the heterogenity of
the data-structure by using the abstractions that implement it, and focus on
writing the data-structures more.

%package devel
Summary: Development files for %{name}
Requires: %{name}%{?_isa} = %{?epoch:%{epoch}:}%{version}-%{release}

%description devel
Development files for %{name}.

%prep
%autosetup

%build
%meson
%meson_build

%install
%meson_install

%check
%meson_test

%files
%{_libdir}/libsycontainer.so

%files devel
%{_includedir}/sycontainer/
%{_libdir}/pkgconfig/sycontainer.pc

%post -p /sbin/ldconfig
%postun -p /sbin/ldconfig

%changelog
* Fri Feb 26 2021 Goutham Krishna K V <gauthamkrishna9991@live.com> -
- Release 1.0.0 - 1.
- All of the data-types have passed the normal tests, of being contained in sycontainer.
