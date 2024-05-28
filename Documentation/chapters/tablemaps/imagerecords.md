# Image Records 

## Description

Image records serve multiple purposes. The first purpose is for regions
that use the Image transform. When a region requires this type of
lookup, the screen scraper engine will first look for an exact
pixel-for-pixel image match in the Image records, and if no match is
found, will then look for the closest match (with the 65% tolerance, as
described in the Region Records {Technical Reference} section). The
second purpose of the Image records is to serve as a reference from
which Hash records are created (see the {Hash Records} section). Note:
Image transforms are very CPU intensive, as they require 2 passes
through the Image records, the first to try to find an exact match, and
the second to find a closest match. Each pass requires a comparison of
every single pixel in the region. For large regions, this is a lot of
comparisons. The time required to do Image transform lookups is directly
proportional to the number of Image records present, and the size of the
requesting Region record. It almost always makes more sense to use the
Hash transform to do image matching, as the Hash lookup algorithm is
orders of magnitude faster.

## Manipulating image records using OpenScrape

![image](images/os_editor_create_image_record.jpg)

The “Create Image” button on the Table Map Editor window is used to
create new Image records. This button is only available if a region
record has previously been selected.

When the “Create Image” button is clicked, the following window will
appear:

![image](images/os_editor_new_image.jpg)

The only required piece of information on this window is the name of the
Image record, however, the name you choose is crucially important, as
this name is what is returned to the game state engine directly for an
Image transform, and is what is populated on the Hash record when you
create a hash from this image.

The name is dependent on what the image is used for, but for example, if
this is an image of the ace of clubs, you would want to name it “Ac”. If
this is an image of a dealer button, you would want to name it “dealer”.
(See the Region Records section, {Technical Reference}, for valid return
values for each region)

## Technical Reference 

In the Table Map (.tm) file, these records will be preceded with the
characters i\$. Image records have the following format:

<span class="smallcaps">i\$\<name\> width height</span>

<span class="smallcaps">scanline0</span>

<span class="smallcaps">scanline1</span>

<span class="smallcaps">...</span>

<span class="smallcaps">scanlineN</span>

\<name\> is the description of the image, and is the value returned to
the screen scraper engine or is the name given to an associated Hash
record \<width\> and \<height\> are integer values that give the size of
the image \<scanline0\> - \<scanlineN\> contain the raw 32bit
hexadecimal values for each pixel. Each pixel is in the form BBGGRRAA.
There is no whitespace between pixel values. Each scanline is terminated
with a standard Microsoft Windows line ending (carriage return/line
feed). The number of scanline records is equal to the height of the
image. The text length of a scanline record is width\*8.
