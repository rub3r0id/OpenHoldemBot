# OpenHoldem Directory

<figure>
<img src="images/installation.jpg" />
</figure>

In the OpenHoldem directoryyou will find the following files and
sub-directories:

- OpenHoldem.exe, ManualMode.exe, OHReplay.exe, Rebuy.exe — these are
  the main files for each of the programs in the OpenHoldem project.
  Details on how to use each of these are throughout this manual.

- versus.bin — this optional file is a large lookup table that is used
  by the versus symbols. As the versus database is quite large and does
  not change it is not included in the archives with recent executables.
  It is available at
  <https://github.com/OpenHoldem/openholdembot/blob/master/versus.bin/versus.bin_for_OpenHoldem_2007-10-13.rar?raw=true>
  and should be extracted to the OpenHoldem directory.

- A file with .ini extensions — this is the configuration file with your
  preferred settings; OpenHoldem won’t store any information in the
  registry but use an ini-file instead; it can be named whatever you
  like, OpenHoldem will use it automatically, as long as there is only
  one ini-file in the directory.

- OpenHoldem_Manual.chm — this manual.

- OpenPPL_Manual.chm — the OpenPPL manual.

- pokertracker_query_definitions.dll — a small DLL that contains the
  queries for all PokerTracker-symbols.

- symbols_pokertracker.pdf — a short PDF-guide to the
  PokerTracker-symbols. This is a separate document, because the concept
  of query-definitions in a PokerTracker-DLL allows regular updates and
  fast additions of new PokerTracker-symbols.

- OpenPPL_Library.ohf — a plain-text library that contains the
  definition of several 100 poker-logical symbols like
  StartingStacksize, NumberOfRaisesOnTurn, HadTopPairOnFlop, Position,
  etc. The OpenPPL-library will be loaded silently in the background and
  all symbols are automatically available both for OpenPPL and
  OH-script-users.

- dbghelp.dll — this is a Microsoft file that is used to produce memory
  dumps on critical errors. These memory dumps are useful for the
  developers to diagnose issues.

- keyboard.dll, mouse.dll, scraper.dll, user.dll — these files are all
  extensions to OpenHoldem that you can use to customize the software.
  More detail on all of these are provided in this document.

- \*.lib-files – these are linker files, necessary to link executables
  and DLLs against each other.

- Files with .pdb extensions — these files contain the debug symbols
  that are required if you want to diagnose crashes or simply trace
  execution in a debugger. These files are usually not distributed with
  the executables as most end-users don’t need them and the people who
  want to debug OpenHoldem are usually able to create debug-executables
  on their own.

- Documents-directory – this directory contains useful information like
  the release-notes that document changes and the license-information
  (GPL v3). Feel free to peruse these if you have problems falling
  asleep some night.

- Logs – this directory contains the log-files of the OpenHoldem bots.
  The logs are named “oh_0.log” .. “oh_24.log”. The log-files provide
  very useful information if you want to track down mis-plays or even
  bugs. To get the correct file for a certain instance of OpenHoldem you
  can also use “Menu -\> Edit -\> View Log File” and OpenHoldem will
  open a text-editor with the correct log.

- Hand_Histories — this directory contains auto-generated hand-histories
  for poker-sites that don’t store hand-histories at your hard-drive.

- Scraper – this directory contains the tablemaps for your favourite
  casinos. Just add your new tablemaps there once they have been tested;
  OpenHoldem will then load these tablemaps, so that its auto-connector
  will be able to connect out-of-the box to any open table and start
  playing.
