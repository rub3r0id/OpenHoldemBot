# Planning a Hopper 

Creating a bot that wins (or buying a bot that makes the botter whine)
is one thing. Putting it to the tables regularly to make some volume is
another task that can be time-consuming and boring. Of course this one
can be automated too, but only some tasks of the job are directly
supported by OpenHoldem. OpenHoldem is mainly designed as a
single-tabling poker-playing application. It is not designed for
handling multiple windows (lobby, registration popups), scheduling
sessions or interpreting non-numerical input. In this chapter we will
consider the tasks that usually need to be done by a hopper.

## Preparatory task

- Start the casino

- Take care about potential casino updates

- Log in with username and password

- Prepare / verify correct settings

- Prepare the lobby (game-type and level)

## Main hopper loop

- Select new tables (they might or might not open immediatelly, e.g if
  you register to a tournament)

- Buyin with the desired amount (once the table is open)

- Choose an empty seat

- Supervise the number of open tables (including registered tournaments
  that are expected to open soon)

- Manage the session time (open tables until end of session - x)

## Final tasks

- Wait until all tables are finished and closed

- Close the lobby

- Close all instances of OpenHoldem (if desired)

## Tasks that can be done by OpenHoldem

- Automatically start new instances of OpenHoldem for popup-blocking and
  for the next table (since OpenHoldem 8.0.1)

- Connect to new tables that do not yet get served by other instances of
  OpenHoldem

- Arrange the poker-tables in a non-obstructive way so that every table
  can be scraped properly

- Close popups (true windows with the popup-blocker, painted
  casino-advertisements that look similar to windows with the
  i86-spam-buttons)

- Tick “wait for big-blind” in cash-games

- Tick “auto-post blind”

- Click “sitout” / “leave”, e.g based on session-time, opponents and
  PokerTracker stats.

- Click “rematch”

- Execute a custom rebuy-script if f\$rebuy returns a positive number
  (rebuy-amount in dollars)

- Click the \[x\] in the title-bar to close the poker-table if f\$close
  is true

- Disconnect if the table disappears and be ready for the next table

- Shutdown OpenHoldem, using the f\$terminate-function (since OpenHoldem
  8.0.1)

## Architectural conclusions

As you can see a hopper can be devided into four functional parts

- Starting and configuring software

- Closing software

- Starting new tables, the main hopper loop

- Managing a connected table (singular!)

The first two jobs are more or less trivial. Opening new tables in the
main hopper loop is the main part of a hopper that can’t be done by
OpenHoldem (designed as: single bot, single table, single window). So
all you truely need nowadays is a *table-opener* (fire and forget).
There are cheap and good table-openers available for the main casinos
that get used by flesh-and-blood poker-players. Only for smaller
pokersites you have to create such a thing on your own.

All the remaining tasks (posting blinds, rebuys, closing the table) can
be done with OpenHoldems built-in hopper functionality that got added
over time. This is not too difficult and only requires the configuration
of a handful hopper-functions like f\$sitout and f\$close, plus some
casino-specific tablemap-regions (sitout button) to make it work
everywhere. Finally a small example to demonstrate the simplicity of
OpenHoldems hopper-functions:

    ##f$close##
      WHEN (issittingout
        AND handsplayed > 0
        AND elapsedauto > 120)  // No autoplayer action since 2 minutes
      RETURN TRUE FORCE

.
