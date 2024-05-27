# OpenHoldem Preferences 

Stealth preferences control various detectable components of OpenHoldem,
and are primarily useful in setting up a highly stealthed environment.
See the {Stealth} chapter for more information.

<figure>
<img src="Images/preferences_stealth.JPG" />
</figure>

- *Simple Main Window Title*: By default, OpenHoldem will include all
  sorts of useful information in its window title bar. This useful
  information is also easily identifiable by the casinos’ poker
  software. Check this preference to use a simple window title instead.
  OpenHoldem will then use the name of the executable in its title. For
  example if you rename the OpenHoldem binary to “ChessBase.exe” the
  title will be “ChessBase”.

- *Mutex Name*: OpenHoldem uses system-wide mutexes to ensure that
  multiple running instances of OpenHoldem do not interfere with each
  other when performing Autoplayer actions. The name of this system-wide
  mutex is easily identifiable by the casinos’ poker software and it is
  suggested that this be changed to something else.  
  *Remark:* You have to restart all instances of OpenHoldem when you
  chance the mutex name, otherwise the synchronization will fail.

- *Window Class Name*: Every window running under Microsoft Windows has
  a specific “class name” associated with it. This is easily
  identifiable by the casinos’ poker software and it is suggested that
  this be changed to something else.
