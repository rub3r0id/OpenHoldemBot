# Choosing an operating system

OpenHoldem has been originally designed to work on the 32-bit versions
of Microsoft’s Windows 2000 and Windows XP operating systems, but it
supports all later versions too (and Windows 2000 no longer). When
choosing a botting machine and an operating system the following points
have to be considered:

- Does your favourite casino work at this system?

- How much resources – especially RAM – do the operating system and the
  casino need? (CPU is secondary, as at least OpenHoldem doesn’t use
  much computing power. The author of this manual page could easily
  250-table at one of his machines if there were no crappy casinos and
  no casino security). Being light-weight means that you could run
  multiple virtual machines at one hardware for better stealth and/or
  multiple casinos at the same time.

- Do you want to exchange tablemaps with other botters? (In the past
  most tablemaps were designed for Windows 2000 classic style, but since
  the introduction of automatic table-resizing most tablemaps work
  independently of the desktop theme.)

- Does your favourite casino support overlapping tables? The ability to
  take screenshots of partially or temporary hidden tables greatly
  improves the quality of the input and significantly reduces the risk
  of incorrect decisions if e.g. the table-hopper opens a new table that
  for a short moment overlaps another table that requires action.

The ability to scrape overlapping tables is only available at the more
modern operating systems, but not at the light-weight ones like Windows
2000 or Windows XP. So each operating system has its pros and cons and
unfortunately there is no one that combines all the positive sides. So
let’s have a look at a concrete list.

- *Windows 2000*: completely outdated nowadays. MicroSoft ended support
  for this operating system and most casinos require more modern
  operating systems. Our compiler (MicroSoft Visual Studio 2015
  Community Edition) does no longer create code for this system either,
  so OpenHoldem (the official version) no longer supports Windows 2000.
  If you really need it you would have to downgrade the project files
  and compile on your own.

- *Windows XP*: just like Windows 2000 this operating system is a bit
  old, but most casinos still support it and and many botters prefer it
  for its stability and its small memory footprint. To reduce the memory
  usage even further many botters install minimalistic light-weight
  versions (called e.g. “Tiny XP”).

- *Windows Vista*: this operating system requires more resources than
  Windows XP, it needs at least 512 MB RAM (but this won’t be enough, as
  the system alredy usess 448 MB minimum)..But Windows Vista provides a
  major advantage: scraping overlapping tables if the aero theme is
  enabled. No longer any bad input due to occluded tables is a major
  advantage for any screen-scraping poker-bot, that might out-weight the
  small disadvantages

- *Windows 7*: considered more stable as Windows Vista and according to
  a poll preferred by 40% of all botters nowadys. One common “problem”
  with Windows 7 however is its restrictice user account control (UAC).
  Most people finally chose to run OpenHoldem (and other botting
  software like hopper and Bring) as administrator.

- *Windows 8*: nearly unused in the botting-world, so we can’t really
  assess this operating system.

- *Windows 10*: this is the most stable version of Windows we have ever
  seen and it supports overlapping tables out of the box. On the
  downside it needs at least 2 GB of RAM, but RAM is cheap nowadys, so
  Windows 10 became the preference of some experienced botters.
