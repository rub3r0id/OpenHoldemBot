# Table of contents

* [Introduction](#introduction)
* [The software](#the-software)
* [Table maps](#table-maps)
* [The bot-logic](#the-bot-logic)
* [User-dll](#user-dll)
* [Openholdem extensions](#openholdem-extensions)
* [Real-money botting](#real-money-botting)
* [Various topics](#various-topics)

<br>

# Contents
## Introduction
* Introduction
	* [Thank you to all volunteers!](chapters/thanks/thanks.md)
	* [What is openholdem](chapters/introduction/whatisopenholdem.md)
* [What openholdem is not](chapters/introduction/whatopenholdemisnot.md)
	* [Winholdem heritage](chapters/introduction/winholdemheritage.md)
	* [A (few) word(s) of caution](chapters/introduction/caution.md)
	* [Openholdem references](chapters/introduction/openholdemreferences.md)
* How openholdem works
	* [Connecting to a table](chapters/how_oh_works/connecting_to_a_table.md)
	* [The heartbeat-cycle](chapters/how_oh_works/heartbeat_cycle.md)
	* [The bot-logic (oh-script)](chapters/how_oh_works/bot_logic_oh_script.md)
	* [The bot-logic (openppl)](chapters/how_oh_works/bot_logic_openppl.md)
	* [Backup actions](chapters/how_oh_works/backup_actions.md)
	* [Gecko, our default bot](chapters/how_oh_works/gecko_our_default_bot.md)
	* [Hopper functions](chapters/how_oh_works/hopper_functions.md)
	* [Log-files](chapters/how_oh_works/log_files.md)
	* [Favourite failures](chapters/favourite_failures/favourite_failures.md)
* Installation and setup
	* [Choosing an operating system](chapters/installation/choosinganoperatingsystem.md)
	* [Configuring the operating system](chapters/installation/configuringtheoperatingsystem.md)
	* [Installing the software](chapters/installation/installingthesoftware.md)
	* [Openholdem directory](chapters/installation/openholdemdirectory.md)
	* [Finding a table map](chapters/installation/findingatablemap.md)
	* [Uninstallation](chapters/installation/uninstallation.md)
* License: gpl v3
	* [License: gpl v3](chapters/license_gpl_v3/LICENSE.md)
	* [Frequently asked questions about the gnu licenses](https://www.gnu.org/licenses/gpl-faq.html)
<br>

## The software
* Gui
	* [Main menu](chapters/gui/main_menu.md)
	* [Toolbars](chapters/gui/toolbars.md)
	* [Table display](chapters/gui/tabledisplay.md)
	* [Statusbar](chapters/gui/statusbar.md)
* [Preferences](chapters/preferences/preferences_title.md)
	* [Autoconnector](chapters/preferences/autoconnector.md)
	* [Autoplayer](chapters/preferences/autoplayer.md)
	* [Chat](chapters/preferences/chat.md)
	* [Configuration checks](chapters/preferences/configuration_checks.md)
	* [Debugging](chapters/preferences/debug.md)
	* [Dll extension](chapters/preferences/dllextension.md)
	* [Gui](chapters/preferences/gui.md)
	* [Hand history generator](chapters/preferences/handhistory_generator.md)
	* [Logging](chapters/preferences/logging.md)
	* [Pokertracker v4](chapters/preferences/pokertracker.md)
	* [Popup blocker](chapters/preferences/popup_blocker.md)
	* [Rebuy](chapters/preferences/rebuy.md)
	* [Replay frames](chapters/preferences/replayframes.md)
	* [Scraper](chapters/preferences/scraper.md)
	* [Stealth](chapters/preferences/obscurepreferences.md)
	* [Table positioner](chapters/preferences/table_positioner.md)
	* [Validator](chapters/preferences/validator.md)
* Formula editor
	* [Formula editor](chapters/formula_editor/formulaeditor.md)
	* [Hand list editor](chapters/formula_editor/hand_list_editor.md)
	* [Debug-tab](chapters/formula_editor/debug_tab.md)
	* [f$test](chapters/formula_editor/f_test.md)
	* [OpenPPL mode](chapters/formula_editor/openppl_mode.md)
* ManualMode
	* [ManualMode](chapters/manualmode/manualmode.md)
* OHreplay
	* [Replay frames](chapters/replayframes/replayframes.md)
	* [OHreplay](chapters/ohreplay/ohreplay.md)
* Poker tracker
	* [Poker tracker](chapters/pokertracker/pokertracker.md)
<br>

## Table maps
* Introduction
	* [Creating a table map](chapters/tablemaps/tablemap.md)
	* [Connecting openscrape to the table](chapters/tablemaps/connectopenscrapetothetable.md)
	* [Familiarizing yourself with openscrape](chapters/tablemaps/familiarizingwithopenscrape.md)
* Scraping in practice
	* [Seated, active, playing](chapters/scraping_in_practice/seated_active_playing.md)
	* [Starting a new map](chapters/scraping_in_practice/starting_a_new_map.md)
	* [Getting started](chapters/scraping_in_practice/getting_started.md)
	* [Hashing images](chapters/scraping_in_practice/hashing_images.md)
	* [Collecting fonts](chapters/scraping_in_practice/fontcollectingexample.md)
	* [How to create a table map](chapters/scraping_in_practice/howtocreateatablemap.md)
	* [Interface-buttons explained](chapters/scraping_in_practice/interface_buttons_explained.md)
	* [Interpreting titletext](chapters/scraping_in_practice/interpreting_titletext.md)
* Expert tricks
	* [Scraping &quot;10&quot; as t](chapters/expert_tricks/scraping_10_as_ten.md)
	* [Scraping cents and dollars](chapters/scraping_in_practice/scraping_dollars_and_cents.md)
	* [Scraping non-standard titles](chapters/expert_tricks/scraping_non_standard_titles.md)
	* [Defining the game-type](chapters/scraping_in_practice/setting_the_game_type_to_nolimit.md)
	* [Scraping fonts which are glued together](chapters/expert_tricks/scraping_fonts_which_are_glued_together.md)
	* [Scraping blinking fonts and nameplates](chapters/expert_tricks/scraping_blinkiung_fonts_and_nameplates.md)
* Technical reference
	* [Size records](chapters/tablemaps/sizerecords.md)
	* [Region records](chapters/tablemaps/regionrecords.md)
	* [Symbol records](chapters/tablemaps/symbolrecords.md)
	* [Font records](chapters/tablemaps/fontrecords.md)
	* [Hash point records](chapters/tablemaps/hashpointrecords.md)
	* [Hash records](chapters/tablemaps/hashrecords.md)
	* [Image records](chapters/tablemaps/imagerecords.md)
<br>

## The bot-logic
* Built-in symbols
	* [Symbols](chapters/symbols/symbols.md)
	* [The multiplexer-engine](chapters/symbols/multiplexer.md)
	* [Symbols poker tracker 4](chapters/symbols/symbols_pokertracker.md)
	* [Starting hand ranking](chapters/handrank/handrank.md)
* OH-script
	* [Syntax](chapters/oh_script/oh_script_syntax.md)
	* [Hand lists](chapters/handlists/handlists.md)
* OH-script explained
	* [Prwin and versus](chapters/oh_script_explained/prwin_and_versus.md)
	* [Iterations and standard deviations for prwin](chapters/oh_script_explained/iterations_and_standard_deviations.md)
	* [Icm - the independent chip model](chapters/oh_script_explained/icm_explained.md)
	* [Pokerval explained](chapters/oh_script_explained/pokerval_explained.md)
	* [Memory symbols](chapters/memory_symbols/memory_symbols.md)
	* [Rankbits](chapters/oh_script_explained/rankbits_explained.md)
* Winngys hand strength library
	* [Handstrength symbols](chapters/oh_script_explained/handstrength_library.md)
	* [Myhand explained](chapters/symbols/myhand_explained.md)
<br>

## User-dll
* [User-dll](chapters/dll/dll.md)
* Dll-tutorial
	* [Compiling the first dll](chapters/dll_tutorial/part_a_compiling_the_first_dll.md)
	* [Basic overview over the dll structure and examples](chapters/dll_tutorial/part_b_basic_overview.md)
	* [Setting up the *.ohf file for dll use](chapters/dll_tutorial/part_c_setting_up_ohf_for_dll.md)
	* [Using prw1326](chapters/dll_tutorial/part_e_using_prw1326.md)
<br>

## Openholdem extensions
* [Mouse-dll](chapters/extensions/mousedll.md)
* [Keyboard-dll](chapters/extensions/keyboarddll.md)
* [Pokertracker-query-definitions-dll](chapters/extensions/pokertracker_query_definitions_dll.md)
* [Chat](chapters/chat/chat.md)
<br>

## Real-money botting
* Automation
	* [Automation](chapters/automation/automation.md)
	* [Planning a hopper](chapters/automation/planning_a_hopper.md)
	* [Autoit - the language of choice](chapters/automation/autoit.md)
	* [Scout - an open-source hopper](chapters/automation/scout.md)
	* [Avoid race conditions](chapters/automation/avoidraceconditions.md)
	* [Setting process cpu afinity](chapters/automation/settingprocesscpuafinity.md)
	* [Setting windows classic theme](chapters/automation/setting_windows_classic_theme.md)
	* [Rebuys](chapters/automation/rebuys.md)
	* [Handling popup windows](chapters/automation/handling_popup_windows.md)
	* [Table changes in mtts](chapters/automation/table_changes_in_tournaments.md)
* Stealth
	* [Stealth](chapters/stealth/stealth.md)
	* [Your worst enemy](chapters/stealth/your_worst_enemy.md)
	* [Casino security levels](chapters/stealth/colour_coded_pokersites.md)
	* [The grand plan](chapters/stealth/the_grand_plan.md)
	* Single system configuration
		* [Single system configuration](chapters/stealth/singlesystemconfiguration.md)
		* [Casino software](chapters/stealth/casinosoftware.md)
		* [Ninja setup](chapters/stealth/ninjafolders.md)
		* [Stealth preferences](chapters/stealth/obscurepreferences.md)
		* [Ini-files and registry](chapters/stealth/registry.md)
		* [Rootkits](chapters/stealth/rootkits.md)
	* Dual system configuration
		* [Dual system configuration](chapters/stealth/dualsystemconfiguration.md)
		* [Virtualization](chapters/stealth/vmware.md)
		* [Bring](chapters/stealth/bring.md)
<br>

## Various topics
* [Outdated features and known incompatibilities](chapters/outdated_featurees_and_incompatibilities/incompatibilities.md)
* [Contributing to the manual](chapters/contributing_to_the_manual/contributing_to_the_manual.md)
<br>
<br>

<figure>
<img src="openholdem.jpg" />
</figure>