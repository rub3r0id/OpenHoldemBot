# OpenHoldem Preferences – Autoconnector

Autoconnector preferences control how the OpenHoldem Autoconnector
functions. See the {The Automation} section for more information.

<figure>
<img src="Images/preferences_autoconnector.JPG" />
</figure>

- *Auto-Connect*

  - *Never:* The former default but now outdated classical method. The
    clumsy and error-prone manual-connection is gone, but this option is
    still supported for the rare case that anybody wants to control all
    connections with his hopper. Please refer to the chapter
    “Automatization” for more details.

  - *Once on start:* This option will cause OpenHoldem to auto-connect
    exactly once on start. This setting is especially useful in
    combination with the option to automatically choose a table. If no
    table exists, that fits to a tablemap — or if all such tables are
    already getting served — , it will fail silently and behave the
    default way, waiting for a connection-message.

  - *Permanent*<span class="smallcaps">:</span> This setting will cause
    OpenHoldem to try to auto-connect once every heartbeat. After some
    refactoring OpenHoldem does now cache the connection-data of all
    known table maps and all instances of OpenHoldem are now
    synchronized. If one instance fails to connect, the other ones will
    be blocked for the next N seconds. So the system-load is now
    astonishing low, even with dozens of instances waiting for tables.
    Therefore this option became the new default.

- *Close OH when table disappears:* This option will terminate
  OpenHoldem, when the poker table stops to exist, e.g. when the table
  got closed by the hopper or when you get moved to another table in a
  MTT. This method is for you, if your philosophy to do reconnects is to
  close OpenHoldem and to simply fire up another instance or if you want
  to easily shut your botting system down at the end of a session.
