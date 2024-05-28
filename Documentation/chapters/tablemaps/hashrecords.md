# Hash Records

## Description 

The purpose of Hash Records is to allow for the rapid lookup of pixel
patterns, without having to scan through each pixel in a region to find
a match. For example, if we have a card region specified to use a
“Hash0” transform, the screen scraper engine will first reduce the
pixels in that region to a 32-bit hash value. (A link to Bob Jenkins’
hash algorithm that is used in this project can be found in the
references section) Once the screen scraper engine has calculated the
32-bit hash value, it looks to see if there exists a matching 32-bit
value in the associated group of Hash Records, in this example, group 0.
If a matching 32-bit hash value is found, the screen scraper engine
returns the \<name\> of the Hash Record to the game state engine.

## Manipulating hash records using OpenScrape

Hash Records are created from specific Image records, so in order to
create a Hash record, you must first have collected the associated Image
record (see section {4.9}).

![image](images/os_editor_create_hash.jpg)

The “Create Hash” buttons on the Table Map Editor window are used to
create new Hash records. Button “0” creates Hash records in the Hash0
group, button “1” creates Hash records in the Hash1 group, and so on.
These buttons are only available if an Image record has been selected in
the tree display on the Table Map Editor window.

Note: Only one Hash record can exist in a Table Map in each hash group
for any given Image record. Otherwise, there would be collisions, and
the screen scraper engine would not know which Hash record was the
correct match. In the “Create Hash Record buttons” screenshot above,
Hash records for group 0 and 2 have already been created for the
selected Image record, so those buttons are grayed out.

To create a new Hash records:

1.  Select an Image record

2.  Click the “Create Hash” button for the hash group that you want to
    create this Hash record in.

The following window will then appear to confirm the addition of the new
Hash record:

![image](images/os_editor_hash_conformation.jpg)

When you add a new Hash record with the “Create Hash” buttons,
OpenScrape will calculate the hash value for you and add it to the
record. (This is new behavior in 2.0; previous versions stored a zero
hash value on new record creation) However, sometimes you may need to
change that stored hash value, if for example, you replace the
underlying Image record, or you change the number or location of the
related Hash Points. If one or more hash values need to be updated, use
the “Update Hashes” option on the Edit manu on the Main window, and the
hash values on all Hash records will be re-calculated. Technical
Reference In the Table Map (.tm) file, these records will be preceded
with the characters h\$. Hash records have the following format:

h\<n\>\$\<name\> \<value\>

\<n\> is the group (1-3) that this hash record belongs to \<name\> is
the string that is returned to the scraper engine upon a match (the
“result”) \<value\> is a 32bit hexadecimal value that contains the
calculated hash .
