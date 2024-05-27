# Size Records 

## Description 

Size records are used for one purpose only, to allow OpenHoldem’s
auto-connector to find windows of the correct size. More specifically,
they provide the ability to specify the accepted sizes for the casino
table that the scraper engine will recognize.

<figure>
<img src="images/OH_clientsize.JPG" />
</figure>

Upon connection OpenHoldem will look for poker table windows that are
between the *clientsizemin* and *clientsizemax* sizes. Thereafter it
will use *targetsize* to resize the table one time after connection to
the preferred size (if resizing is needed at all).

## Manipulating size records using OpenScrape 

To create a new size record, select the “Sizes” category in the record
tree display on the Table Map Editor window, and click the “New” button.
A window will be displayed that allows you to enter the width and height
parameters for this new record. To edit an existing size record, select
the record in the record tree display on the Table Map Editor window,
and click the “Edit” button. A window will be displayed that allows you
to adjust the width and height parameters for this record, or change the
record name itself. To delete an existing size record, select the record
in the record tree display on the Table Map Editor window, and click the
“Delete” button. A window will be displayed asking for verification of
this action.

A note about window client sizes: Microsoft Windows provides several
different measures of a windows’ size, such as the complete window
including frame and title bar, and an altogether different measure, the
so-called “client area”, that lies inside the window frame and excludes
frames and title bars. OpenHoldem references the Microsoft “client area”
measurement for these “Size” records. To help you understand the size of
the poker window that you have attached to (with the Green Circle
Button), OpenScrape always displays the client size of the attached
poker table in the “View” menu on the main OpenScrape window. The menu
option is at the bottom of this menu and is preceeded by “Current Size:
“. The width and height displayed in this menu can be entered directly
into a clientsize record.

<figure>
<img src="images/OS_edit_clientsize.JPG" />
</figure>

## Technical reference 

In the Table Map (.tm) file, the size records will be preceded with the
characters z\$”. These records have the following format:

`z$<name> <width> <height>`

\<name\> is the name of the record (see table below) \<width\> and
\<height\> are integer values.

Valid size records and their descriptions:

| Size record | Description |
|:---|:---|
| clientsizemin | Specifies the minimum allowed client size of the poker table window. |
| clientsizemax | Specifies the maximum allowed client size of the poker table window. |
| targetsize | Specifies the optimal size of the poker table window. If this parameter gets used the table will be resized once after connection to match the perfect size. |
