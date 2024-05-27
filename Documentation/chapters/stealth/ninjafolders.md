# Ninja Setup

(Constructed from Tammelins posts here:
<http://forum.winholdem.net/wbb/viewtopic.php?t=4749>. and here
<a href="http://forum.winholdem.net/wbb/viewtopic.php?t=11894 "
class="uri">http://forum.winholdem.net/wbb/viewtopic.php?t=11894 </a>.)

This article explains the basic steps for creating a windows folder that
will be as secure as it can possibly be under the NTFS file system.

The general goal is to create a folder that is owned by a single windows
user account (“Ninja”) such that no other user account may access the
folder – not even the system or the admin account. Other users
(including casinos that demand running as administrator) will also be
unable to view the processes started by the Ninja-account. Therefore a
Ninja-setup provides the same stealth like a rootkit, but it does not
require any additional – and potentially compromising – software. The
Ninja-setup achieves this level of stealth just with default Windows
security-functionality.

## Prerequisites

1.  knowledge of creating/modifying user account

2.  knowledge of windows explorer

3.  knowledge of NTFS permissions

It is assumed that the reader understands how to create/modify a user
account and how to use Windows Explorer to navigate folder space and how
to modify folder properties/permissions.

## User Accounts

First we create two user-accounts with limited permissions, one for the
casino and the other one for the stealthed poker-bot (“Ninja”).

1.  Click Start - Control Panel - User Accounts.

2.  You had already set up one user while installing Windows. This user
    already has admin privileges. We’ll call it the admin user. We need
    to give this user a password. Click on the user, then click on
    create a password. Enter the password into the boxes and click on
    create password. The next window asks you if you want to make your
    files and folders private. You certainly do, so click Yes, make
    private. Click on Back to return to the user accounts window.

3.  Now we’ll set up two new users with fewer privileges. You will be
    logged in as the second user whenever you connect to a casino. We’ll
    call this the casino user. The third user will be created to hide
    things from the casino. We’ll call this the “Ninja” user.

4.  Choose names and passwords for these users, and write them all down
    now.

    |                |                                                    |
    |:---------------|:--------------------------------------------------:|
    | *Admin user*   | \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ |
    | *Casino user*  | \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ |
    | *Stealth user* | \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ |

5.  The casino user will have restricted privileges initially. Click
    create a new account, enter the name of the casino user and click
    next. Click on limited and then click on create account. The casino
    user will appear next to the admin user. Click on the casino user
    and give it a password.

6.  The stealth user will have restricted privileges permanently. Click
    create a new account and set up the stealth user in the same way you
    set up the casino user.

7.  Click create a new account. Choose a name and then click on limited
    account.

8.  That completes this step. If there is a guest user shown, you can
    ignore it. Close the user accounts window.

## File System

1.  Create the target folder (from admin account). In an ideal world you
    would create a top level folder on an empty local
    (non-shared/not-networked) hard drive where Ninja has full control
    over that disk. If this is not possible then the next best thing is
    a top level folder on a non-shared drive. If this is not possible
    then you must select a location where Ninja will have access to the
    parent folder so that it can access its private folder.

2.  Permissions (from admin account)

    1.  Select the properties for the folder and select the security tab
        add Ninja to the access list and grant Ninja full control.
        Remove all other users/groups from the access list, including
        the administrator(s), which will effectively shut out the entire
        world. There should be exactly one account in the access list
        and that account should be “\<host\>/Ninja

    2.  Uncheck/unselect Allow inheritable permissions from parent to
        propagate to this object. The reason for this is that you want
        this folder and it’s permissions to be the root node for all
        children below it. If you do not do this then permissions
        defined for the parent above your root folder will filter down
        to your folder and the children in your folder and you do not
        want that. Note that you cannot give ownership of objects in
        NTFS, you can only take ownership with the account you’re
        currently using. You will take ownership of the folder later
        when you login to the Ninja account.

3.  Logout of the admin account

4.  Login to your Ninja account

5.  Ownership (from Ninja account)

    1.  Select the properties for your safe folder and verify that Ninja
        is the only account in the access list.

    2.  Click the advanced button and goto the owner tab and select the
        Ninja account.

    3.  Check Replace owner ... and click Apply. You should now be the
        full owner of your safe folder and everything below it.

6.  Permissions (from Ninja account)

    1.  Click the permissions tab and check Reset permissions on all
        child objects ....

    2.  Uncheck Allow inheritable permissions from parent ... (note this
        should already be unchecked since you did that from the admin
        account), then click apply. This will go quickly if the folder
        is empty. It can take seconds or minutes or more depending on
        the children folder tree below you.

7.  Verify. Create a test child folder inside your safe folder, view the
    properites and verify that Ninja is the owner with full control and
    that no other account has access. If this is not the case then you
    missed a step above (probably the Allow inheritable permissions
    ...).

8.  Logout of the Ninja account

9.  Login to the admin account

10. Verify. Try to access the safe folder. You should not be able to
    access the contents of the folder nor modify the folder
    properties/permissions. As an admin you can still take ownership of
    the folder but until then the admin access is denied.

## Other thoughts

If you have the resources and you want the best possible solution then
you should dedicate an entire physical hard drive to your stealth
department. That drive should not be the bootable system drive, but
should be a secondary drive. You should consume all 4 primary partitions
on your stealth drive by creating 4 primary partitions of roughly equal
size. Each partition should be formatted with NTFS only (not FAT or
FAT32).

You should then make the Ninja account the owner of all 4 partitions and
the sole account with access. There should be no other accounts listed
in the access list. The drives should not be networked or shared. If you
do this you will notice that your admin account cannot even read the
device label and that the 4 hard drives will be seen only as
local-drive. All access from any accounts other than Ninja will be
denied.

The benefit of this setup is that once you construct a hard drive like
this you don’t have to worry about permissions ever again in the context
of that drive - you know that anything you do on that drive must be done
from the Ninja account and that any folder/files created on that drive
are entirely safe.
