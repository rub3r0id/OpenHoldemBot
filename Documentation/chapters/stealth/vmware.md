# Virtualization

This is a guide to show you how to get OpenHoldem running securely on a
single computer using the VMware Server application as a second, virtual
computer. Original post by <span class="smallcaps">Tammelin</span>n:
<http://forum.winholdem.net/wbb/viewtopic.php?t=11894>

I am also assuming that you are using the same operating system as me.
If you are using Windows XP Media Centre Edition or Windows XP
Professional, you can use this guide. If you are using some other brand
of Windows (including Vista), the guide might not be reliable. I have
only tested these instructions with XP. Most steps also apply to other
virtualization software like
([VirtualBox](https://www.virtualbox.org/)), which is a free and equally
good alternative, but this guide concentrates on VmWare, which was state
of the art when these instructions got written.

The guide assumes no special knowledge, but you will need some basic
computer skills. You will need to know how to install software, how to
rename files, how to navigate folders and so on.

Much of this information is already available elsewhere. In many cases,
all I have done is to reword it a little.

### Definitions 

The real computer is the one that is sitting on your desk or on your
lap. It has its own operating system. The virtual computer is the one we
are going to create using VMware Server. We can think of the virtual
computer as a separate computer with its own operating system, even
though it is physically part of the real computer.

<figure>
<img src="images/vmware.jpg" />
</figure>

### Step 1 – Download VMware Server 

VMware Server is a free download from <http://www.vmware.com>. You will
need to provide VMware with a valid e-mail address to get a serial
number. I used version 1.0.3 while writing this guide.

You will also need a Windows installation disk or an ISO-image of e.g.
TinyXP. I am using a Windows XP Professional installation DVD, which I’m
going to install as my virtual operating system.

While you wait for the download to finish, you should read the whole of
this guide and make sure that you understand it. It would be a good idea
to print it out, if you can.

*Do not install any software* until you are told to.

### Step 2 – Install VMware Server on your real computer 

Double-click on the VMware Server file you downloaded and it will begin
installing itself. When you are asked if you want a complete or custom
installation, choose complete. A big window with some warnings about IIS
might appear. We don’t need IIS, so just click “OK”. When the installer
asks for Internet access, grant it. Wait for the installation to
complete before moving on to the next step.

### Step 3 – Configure VMware Player 

Double-click on the VMware Server icon that should have appeared on the
desktop of your real computer. VMware Server will start for the first
time. A Pop-up window asks you to choose between a local host and a
remote host. Choose local host and click OK.

Click the New Virtual Machine icon and a window will appear. Choose
typical and click next. Now choose which operating system you want to
install on your virtual computer. Here, I selected the Microsoft Windows
option, and the version I selected was Windows XP, Professional. if you
want to install from a CD-image and not from a real CD then just point
VMware to the location of the ISO-image.

The next window gives you two boxes to fill in. The first box gives you
a chance to name your new virtual computer. Choose any name you like.

The second box (Location) allows you to choose where the Virtual
computer will be saved on your hard drive. You probably don’t need to
change the contents of this box. (The virtual computer is actually a
single file which exists on the hard drive of your real computer. If you
want this file to be in a different folder or even on a different
partition, you can tell VMware now.)

Next you must choose the type of network. Choose Use bridged networking.

The next window asks you to decide how big the virtual computer’s
virtual hard drive is going to be. The suggested 8GB is quite enough for
the purposes of playing poker. Click Finish when you are ready. Some
operating-systems like Windows 2000 or TinyXP will be satisfied with a
bit less disk space, but don’t forget that you also need space for
casino-software, hand-histories and maybe PokerTracker. Better safe than
sorry.

VMware will thereafter spend quite a few minutes creating the virtual
computer. Wait until the installation is complete. You should be looking
at a brand-new installation of Windows XP. If you can run Solitaire
(click Start - All Programs - Games - Solitaire) then you are ready to
move on to the next step.

### Step 4 – Install an operating system on the virtual computer

When VMware is ready, you’ll see a new window with some details about
the virtual computer. Find Start this virtual machine on the left and
click it. VMware will now look for the Windows installation disk in your
CD/DVD drive. Put the installation disk in the drive and Windows will
begin installing onto your virtual computer.

Soon, Windows will ask you if you want to format your hard drive. Only
the virtual hard drive of the virtual computer is going to get
formatted, so you don’t need to worry about the data on your real hard
drive. It is perfectly safe. If you asked how you want to format the
virtual hard drive, make sure you choose one of the NTFS options. (Do
not choose any option with FAT16 or FAT32).

Eventually, Windows will ask you to enter your full name. We are going
to create three seperate users, so choose a name for the first user
(Jessica, for example) and enter it here. This user will have permanent
administrator privileges.

Next, enter an administrator password for this user. Write down the name
and password now.

*Administrator name and password*
\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Later, Windows will ask you to enter up to five user names. The first
user - the box labelled your name - should be the same as the user you
entered above (Jessica). Don’t fill in the other boxes yet.

Wait until the installation is complete. You should be looking at a
brand-new installation of Windows XP. If you can run Solitaire (click
Start - All Programs - Games - Solitaire) then you are ready to move on
to the next step.

### Step 5 – Install VMTools, Firewall and Antivirus on virtual computer 

VMTools is a package which, among other things, gets the mouse to move
smoothly between the real and the virtual computer. You need to install
it now, so press CTRL+ALT to restore mouse control to the real computer.
Then, on the VMware Server window, click on the menu option VM, and then
choose Install VMTools... VMTools will now install itself inside the
virtual computer. The virtual computer will need to reboot.

After the reboot, find the VMTools icon in the system tray, next to the
clock. It looks like three small interlinked squares. When you have
found it, double-click on it.

A window appears and the Options tab is already showing. Find the line
Show VMware Tools in the taskbar and click on it, so that there is no
longer a tick next to it. Click “OK” to save your changes. This measure
prevents the casino from seeing that you’re using VMware - just in case
they take a screenshot of your desktop.

Now, your virtual computer is connected to the Internet, so it needs
firewall software and antivirus software, just as your real computer
does. Install the software (connect to the Internet to download it, if
you have to), and then run a scan to check that your virtual computer is
free from viruses.

(You could use AVG Antivirus (<http://free.grisoft.com>), and Zonealarm
Firewall (<http://www.zonealarm.com>))

### Step 6 – Check that the real and virtual computers can communicate

If the real computer and the virtual computer can’t communicate with
each other, all your efforts in securing them will be wasted. Let’s
check the communications now.

The traditional way to test a network is to have one computer ping the
other. A ping is a short signal which one computer sends to another. The
signal will get bounced back if the network is running as it should.

Before pinging anything, you need to turn off the firewalls on both
computers. If you have installed a firewall such as Zonealarm, switch it
off. Now click Start - Control Panel - Security Centre. At the bottom of
the window is an option to Manage security settings for: Windows
Firewall. Click on Windows Firewall and make sure it is off. Do this on
both computers.

Now you need to find out the IP address for both computers. (An IP
address is a numerical address which computers on a network use to
identify each other.)

On your real computer, click Start - Run. Type cmd in the box and press
return.

A new window appears. Type “ipconfig and press return. You will see a
series of numbers, some of which are marked IP address. Find the one
that corresponds to the type of Internet connection you have - for
example, the one labeled wireless connection if you connect to the
Internet through a wireless router.

The IP address of my real computer is 192.168.1.4 - yours probably looks
almost the same. Write it down now.

*Real computer IP
address*\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Now do the same thing on your virtual computer. Find the IP address and
write it down. The IP address of my virtual computer is 192.168.1.7 -
yours will be similar.

*Virtual computer IP address*
\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

On your real computer, find the new window again and type ping x.x.x.x,
then press return. Replace x.x.x.x with the IP address of your virtual
computer. You should see something like this...

    Pinging 192.168.1.7 with 32 bytes of data: 
    Reply from 192.168.1.7: bytes=32 time<1ms TTL=128
    Reply from 192.168.1.7: bytes=32 time<1ms TTL=128 
    Reply from 192.168.1.7: bytes=32 time<1ms TTL=128 
    Reply from 192.168.1.7: bytes=32 time<1ms TTL=128 
    Ping statistics for 192.168.1.7: (and so on) 

This dialogue means that the real computer sent a signal to the virtual
computer four times, and each time it got a response.

If the network isn’t set up properly, you will see something like
this...

    Pinging 192.168.1.7 with 32 bytes of data: 
    Request timed out. 
    Request timed out. 
    Request timed out. 
    Request timed out. 
    Ping statistics for 192.168.1.7: (and so on) 

This dialogue means that the real computer sent a signal to the virtual
computer four times, but received no response.

Go to your virtual computer and do the same thing. This time, type ping
x.x.x.x replacing x.x.x.x with the IP address of your real computer. If
you get a response, your network is set up properly and you can continue
to the next step. If the network isn’t set up properly, you should seek
help from someone who understands networks.

Don’t forget to *turn your firewalls back on again* when you finish this
step. If you have a good firewall such as Zonealarm, you can leave the
less powerful Windows firewall turned off permanently (on your real
computer as well as your virtual computer).

### Step 7 – Ninja account

Now setup two restricted user-accounts. One for the casino-software. The
other one for the bring-server that will handle the communication
between your casino-VM and the bot-VM. The necessary steps are described
in the chapter about single-system-configuration and Ninja-setups.

### Step 8 – Install and configure Bring on your virtual computer.

Once you have created the two restricted accounts you should install the
Bring server (but no other software) into the stealthed Ninja-folder.
Bring will handle the communication with the bot-machine and it will
receive and execute the actions on the poker-table. Installing and
configuring Bring will require a couple of extra-steps that are not
related to the VmWare-setup in general, so we made it an extra chapter
(it should be the next one).
