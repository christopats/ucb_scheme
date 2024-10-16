%define		release 1
Summary: 	Scheme Interpreter with access to the Tk toolkit
Name:    	STk
Version: 	
Release: 	%{release}
Copyright: 	distributable
Source: 	STk-.tar.gz
Group:		Development/Languages
Packager:	Erick Gallesio <eg@unice.fr>
BuildRoot:	/tmp/STk

%package devel
Summary: 	Header files and libraries for STk
Group: 		Development/Libraries
Requires:	STk = 

%description
STk is a R4RS Scheme interpreter which can access the Tk graphical
package.  Concretely it can be seen as the John Ousterhout's Tk
package where the Tcl language has been replaced by Scheme.

STk also provides an efficient object oriented system called STklos.
STklos is an extensive OO system with multiple inheritance, generic
functions, multi-methods and a Meta Object Protocol).

This package integrates the 8.0.3 version of the Tk toolkit.


%description devel
This package contains the files necessary for extending, in C, the 
STk interpeter. If you don't need to write some C code for extending
the interpreter, you don't need to install this package.


%ifarch i386
%define machine Linux-2.X-ix86
%else
%ifarch ppc
%define machine Linux-2.X-ppc
%else
%define machine Darwin-23.6.0-arm64
%endif
%endif


%prep

%setup

%build
CFLAGS=-O2 sh configure --prefix=/usr/local
make

%install
rm -rf %{buildroot}
mkdir -p %{buildroot}

make install root=%{buildroot}
make install.libs root=%{buildroot}

%clean

 

%post
if [ -d /usr/local/lib/stk/site-scheme ] 
then 
  mkdir -p /usr/local/lib/stk/site-scheme 
fi

%postun
rm -f /usr/local/lib/stk/man
rmdir /usr/local/lib/stk/site-scheme || true
rmdir /usr/local/lib/stk || true

%postun devel
rm -f /usr/local/lib/stk/include


%files
%doc README INSTALL CHANGES ChangeLog
/usr/local/lib/stk//Demos
/usr/local/lib/stk//Help
/usr/local/lib/stk//Images
/usr/local/lib/stk//%{machine}/stk
/usr/local/lib/stk//%{machine}/snow
/usr/local/lib/stk//%{machine}/*.so


/usr/local/lib/stk//STk
/usr/local/lib/stk//include
/usr/local/lib/stk//man
/usr/local/bin/stk-
/usr/local/bin/snow-
/usr/local/bin/stk
/usr/local/bin/snow

/usr/local/doc/stk-


%files devel
/usr/local/lib/stk//%{machine}/Config
/usr/local/lib/stk//%{machine}/Libs
