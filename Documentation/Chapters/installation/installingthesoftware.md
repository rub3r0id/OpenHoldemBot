# Installing the software 

OpenHoldem and its supporting applications do not come with an
installer. This is by design – installers tend to leave traces on your
system, and in this hobby, the less traces, the better. Stealth will be
discussed in greater depth in a later section, but this installer-less
install is an important part of the stealth strategy.

Since you do not have an installer to do the work for you, there are
several steps you need to take to correctly configure the software on
your machine:

1.  Create your “OpenHoldem” base directory. For purposes of this
    walkthrough, we will create this directory as “c:\mpb” (“My Poker
    Bot” – clever, eh?). You can make this directory anything you want,
    however

2.  Download the compiled binary packages. They can be found at the
    links in the {References} section

3.  Extract all the files from the compiled binary packages into the
    c:\mpb directory, using WinRar, 7-zip or similar software. When
    done, your directory should look something like below.

    <figure>
    <img src="Images/Installation.JPG" />
    </figure>

4.  OpenHoldem got created with MicroSoft Visual Studio 2015 Community
    Edition and needs some extra MicroSoft DLLs (dynamic link
    libraries). Therefore you have to install the redistributable
    runtime-library from MicroSoft:
    <https://www.microsoft.com/en-us/download/details.aspx?id=48145>.
    You need the 32-bit-version, even if you have a 64-bit-system,
    because OpenHoldem still supports older machines with 32 bits.
