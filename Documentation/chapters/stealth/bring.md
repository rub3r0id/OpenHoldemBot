# Bring

“Bring” (<http://www.winholdem.net/bring/index.html>) is a software
program developed by Ray Bornert. The sole purpose of Bring is to enable
a dual-system configuration, and allow the casino’s poker windows from
“System A” to be displayed on “System B” where OpenHoldem can connect to
them.

### Step 1 – Install Bring on your virtual computer

You now have a real computer and a virtual computer. OpenHoldem is going
to run on the real computer. The casino software is going to run on the
virtual computer.

Now you need to install some software that will allow OpenHoldem (on the
real computer) to see what the casino software (on the virtual computer)
is doing. There are several ways of doing this. We are going to use a
piece of software called Bring.

On the virtual computer, log in as the stealth user. Now go to the
official WinHoldem site and download bring.exe (from the stealth page).
Download it directly into the Ninja folder:
<http://www.winholdem.net/bring/>.

The casino software can’t see inside the Ninja folder, but it will be
able to see Bring being run as a process. (If you want to see all the
processes your computer is running, press CTRL+ALT+DEL and then click on
the processes tab.)

The solution is to rename Bring to something more innocent. Then, if the
casino software looks at the processes you are running, it won’t be able
to find out anything incriminating about Bring.

Rename Bring now. For example, you could rename it to notepad or “paint.

### Step 2 – Install software on your real computer

You can now install Bring on your real computer. You don’t need to
rename it; the casino cannot see what is happening on your real
computer.

Open a folder on the desktop, call it Bring, and download into it the
files bring.exe and “bring.ini.

Click Start - Control Panel - Folder Options. Click the View tab. In the
box labeled Advanced Settings, scroll down and find the line Hide
extensions for known file types. If there is a green tick next to this
line, click on it to make the tick disappear. Click OK” to save your
changes.

You should also install OpenHoldem on your real computer now if you
haven’t already. *Do not install OpenHoldem on your virtual computer.*

### Step 3 – Configure Bring 

Do you remember the IP address of your virtual computer? You’re going to
need it again now.

On your real computer, go into the Bring folder you just created and
open the file bring.ini in a text editor. (Right-click on “bring.ini”,
choose Open with... and select Notepad.)

Find the following lines:

    # remotehost      port  password  
    -------------------------------- 
    a 192.168.x.x     ????  prompt 
    b 192.168.x.x     ????  prompt 
    --------------------------------

Change them to this:

    # remotehost      port  password  
    -------------------------------- 
    a x.x.x.x         eeee  secret
    --------------------------------

- x.x.x.x should be the IP address of your virtual computer.

- eeee is the port number. It can be a number of your own choice. 80
  would be a good choice, and so would 800, 5000 or 8080.

- secret is a password. It’s not a good password, but it is fine for the
  purposes of testing Bring.

Here are the changes I made to my bring.ini file:

    # remotehost port password
    -------------------------------- 
    a 192.168.1.7 80 secret 
    -------------------------------- 

### Step 4 – Start Bring 

Now we’re going to test Bring by playing a game of solitaire on the
virtual computer, and by attempting to control it from the real
computer.

Go to the virtual computer. You should still be logged in as the stealth
user. Start the Solitaire programme (Start - All Programs - Games -
Solitaire).

Now open another command prompt (click Start - Run, type cmd and press
enter).

The command prompt window is currently looking at the My Documents
folder. You need to move into the Ninja folder. If you followed the
earlier suggestion, the location of your Ninja folder will be C:\files.
To move into this folder, simply type “CD C:\files and press return. (If
this doesn’t work you will need to learn how to use the command prompt.
Do an Internet search for DOS command prompt.)

Now type the following command and press return. Instead of bring, you
should type the name of your renamed file. Instead of 80, you should
type the port number you chose in the previous step, and instead of
secret you should type the password you chose.

    bring -s 80 secret 

A small pop-up will appear to show you that Bring has started on your
virtual computer. Click OK.

Now go to your real computer. Go into the Bring folder and double click
on bring.exe.

Another pop-up appears to show you that Bring has started on your real
computer. Click “OK”.

Another window appears labeled Select remote connection. You should see
a line that looks exactly like the line you entered in the bring.ini
file.

    a 192.168.1.7 80 secret 

Click on this line so that it turns blue, and click the OK button.

Another window appears with a list of programs that are currently
running on your virtual computer. One of them should be solitaire, so
click on it so that it turns blue and then click the OK button.
Solitaire will launch on your real computer, and if everything is set up
correctly, you will be able to play it and watch your mouse clicks
affecting both computers at once!

If you are unable to control solitaire from your real computer you
definitely won’t be able to control a poker table. Before you continue,
seek help from someone who understands networks.

### Step 5 – Stop running Bring 

When you have had enough of playing solitaire, you should shut down
Bring.

On the real computer, just close the solitaire window.

On the virtual computer, there are three ways to stop Bring.

1.  Log off

2.  Stop the Bring process. Press CTRL+ALT+DEL. Two task manager windows
    will appear, one for the real computer and one for the virtual
    computer. Find the task manager on the virtual computer and click
    the Processes tab, find “bring.exe (however you renamed it), click
    on it to turn it blue, and then click on End Process.

3.  Lock the desktop. This doesn’t actually close Bring, but it does
    halt it and prevent your real computer from communicating with it.

Stop Bring on both computers before you move on to the next step.

### Step 6 – Set up the run as a different user facility 

When you connect to the casino’s Internet site you should always be
logged into your virtual computer as the casino user. However, you will
be running Bring *as if* you will logged on as the stealth user. In this
way, the casino won’t be able to detect that you are using Bring. Here’s
how to do it.

On the virtual computer, log in as the casino user. Right-click on the
desktop and choose New, then choose Shortcut. A window will appear. In
the box, type cmd. Click Next and then click Finish.

A new icon, “cmd.exe, will have appeared on your desktop. It’s actually
a shortcut to the command prompt that you have used a few times before.
Right-click on this shortcut and choose Properties. A window appears and
the Shortcut tab should already be showing. Click the Advanced button.
Find the line which reads Run with different credentials. Click on it so
that a tick appears next to it. Click the OK buttons twice. Run with
different credentials actually means run this program as a different
user.

Start solitaire again. Double click the “cmd.exe shortcut and a window
will appear, asking you which user you want to use to run the program.
Click on the line The following user. Then, enter the stealth user’s
name and password, and click “OK.

The command prompt window appears. It is running as if you were logged
in as the stealth user. We can safely run Bring from this window. Go
into the Ninja folder (perhaps by typing CD C:\files”). Type the
following command, changing the words bring, and secret exactly as you
did in step 4.

    bring -s 80 secret 

Bring’s pop-up window appears, so click the “OK” button.

Now go to the real computer and start Bring there. Try to open the
solitaire window, just as you did before.

Go back to the virtual computer. Press CTRL+ALT+DEL to make the task
manager appear in both windows. Find the virtual computer’s task manager
and select the Properties tab. Check that bring.exe (however you renamed
it) is running under the stealth user, even though you are logged in as
the casino user. Check that sol.exe - the solitaire process - is running
under the casino user.

### Step 7 – Check security with Gaze 

We’re going to make one more security check using the program Gaze. It
can be downloaded from the forums at the WinHoldem official site.
(<http://forum.winholdem.net/wbb/viewtopic.php?t=1114>)

Still on the virtual computer and still logged in as the casino user, go
to the WinHoldem site. There should be two files - gaze.cpp and
“gaze.exe. Download both of them to the virtual computer’s desktop.

Double click on “gaze.exe” to run it. A window will appear, and shortly
afterwards a pop-up labeled Windows - no disk will appear. Click the
Cancel button, and close the Gaze window.

The results of the test have been saved to a file on the desktop called
gaze”. Confusingly, there are now two text files on the desktop with the
same name. Double click one of them to open it in a text editor. If the
first few lines don’t look like this, you’ve got the wrong file.

    Sat Jun 23 17:40:42 2007 
    == 
    PROCESSES 
    == 

    == 
    PROCESS NAME: [System Process] 
    -- WARNING: OpenProcess failed with error 87 (The parameter is incorrect)
    process ID = 0x00000000 
    thread count = 1 parent 
    process ID = 0x00000000 
    Priority Base = 0 

You want to read the report on “bring.exe (however you renamed it).
Press CTRL+F to do a search for this file. When you find it, it should
look like this...

    == 
    PROCESS NAME: bring.exe 
    -- WARNING: OpenProcess failed with error 5 (Access is denied) 
    process ID = 0x00000EE8 
    thread count = 1 
    parent process ID = 0x00000EDC 
    Priority Base = 8 
    WARNING: CreateToolhelp32Snapshot (of modules) failed with error 5 (Access is denied) 
    THREAD ID = 0x00000EEC
    base priority = 8 
    delta priority = 0 

If you can see the message OpenProcess failed with error 5 (Access is
denied), then you will know for sure that the casino user can’t find out
anything incriminating about Bring. Your security checks are now
complete.

Close Notepad, solitaire and the “cmd.exe shortcut. Delete Gaze from
your desktop and empty the recycle bin. Terminate the Bring process.
Reboot the virtual computer.

### Step 8 – Install the casino software 

You can now install the casino software. On the virtual computer, log in
as the casino user. Create a new folder on the desktop called poker.
It’s a good idea to install all your casino software in a single folder.

The casino user currently has restricted privileges. Some casinos insist
that you install their software when logged in as a user with
administrative privileges. Some casinos also insist that you run their
software when logged in as a user with administrative privileges.
Preferably, we would like to install and run the software while logged
in as a user has restricted privileges.

Here is how to set up a typical casino’s poker software.

Still logged in as the casino user, go to the casino web site. Download
their software directly into the poker folder you created moments ago.
Go into the folder and double click on the software. It will begin
installing. When the install asks where you would like to install the
software, choose the poker folder you created moments ago. Don’t let the
install the use the default folder.

If the installation completes without complaints, all is well. However,
if the installation complaints that it needs administrative privileges,
this is what you must do:

Log out from the casino user’s account and log in to the admin user’s
account. Open the User Accounts window just as you did before. Click on
the casino user act and then click on Change the account type. Click on
Computer Administrator and then click the Change Account Type button.
Log out from the admin user’s account and log back into the casino
user’s account.

Try to install the software again. This time it should install without
complaints. Now log out of the casino user’s account and go back to the
admin user account. Change the casino user’s account type back to
limited. Log out of the admin user account and log back into the casino
user’s account.

Now try running the software. If the software complaints that it needs
administrative privileges to run, change the casino user’s account to
Computer Administrator just as you did above. It’s unfortunate that you
have to run the software with administrative privileges, but it’s not
the end of the world.

### Step 9 – Change your video settings 

OpenHoldem is quite fussy about which desktop theme you are using.
Currently, only the Windows XP default style and the Windows 2000
classic style are supported. You must change your desktop theme to one
of these styles on both the real computer and the virtual computer.
Click Start - Control Panel - (Appearances and Themes) - Change the
computer’s theme to do this.

### Step 10 – Start playing poker 

On the virtual computer, start Bring by using the “cmd.exe shortcut.
Start the casino software and choose the table. Make sure the table’s
window is not obscured by any other Windows.

Now go to your real computer, start Bring and try to get the table to
appear in a window. If everything has been set up properly, you should
be able to control the table from your real computer.

Now start OpenHoldem. Press OpenHoldem’s “Green Circle Button” button
and you’re ready to make money!

### Step 11 – How to play in the future

Every time you use OpenHoldem to play poker for you, you must follow
this simple checklist.

1.  Boot up your real computer. Start OpenHoldem.

2.  Boot up your virtual computer and log in as the casino user.

3.  On the virtual computer, use the “cmd.exe” shortcut to run Bring.

4.  Start the casino software. Select a table. Make sure this window
    isn’t obscured by any other windows.

5.  On the real computer, start Bring. Find the window with the poker
    table.
