# PokerTracker Query Definitions DLL<span id="sec:PokerTracker-DLL" label="sec:PokerTracker-DLL"></span> 

As you might have noticed a new DLL is part of OpenHoldem since version
4.2.0: PokerTracker_Query_Definitions.DLL.
<http://code.google.com/p/openholdembot/source/browse/trunk/PokerTracker_Query_Definitions/>
This DLL provides the ability to extend the set of PokerTracker-stats
easily. The interesting part of the DLL is the file
PokerTracker_Queries_Version_4.which h contains the definition of a
struct:

    typedef struct t_QueryDefinition {    
        CString name;    
        CString description_for_editor;    
        CString first_part_of_query;    
        // The queries will be created on the fly,    
        // for both ring-games and tournaments.    
        // There will be an "infix" added, depending on game-type    
        CString last_part_of_query;    
        int stat_group;    
        bool needs_infix_and_second_part; 
    };

- name should be self-explanatory. It is something like icon or vpip.

- description_for_editor is the explanation that will be shown in
  OpenHoldems formula-editor.

- “query” is is the database-query, usually containing one or more 3
  place-holders %GAMETYPE% , %SITEID% and %SCREENNAME%. OpenHoldem will
  build the complete query on the fly and automatically replace these
  place-holders by the correct values. A nice side-effect of this new
  concept: all stats will automatically work for both ring-games and
  tournaments; therefore OpenHoldem does no longer distinguish between
  pt\_ and ptt\_ stats, simply “pt\_” will always work.

- stat_group: this is one of pt_group_basic / pt_group_advanced /
  pt_group_positional. Diffferent groups of stats need different
  sample-sizes to become meaningful or change significantly. Therefore
  OpenHoldem will evaluate these symbols with different update delays
  depending on the number of hands a user has played to achieve a good
  compromise between meaningful stats and a low database-usage.

And all the rest happens automagically. To add a new stat you only have
to change the constant

    const int k_number_of_pokertracker_stats = 29;

and append your stat to the array

    t_QueryDefinition query_definitions[k_number_of_pokertracker_stats] = 
    {    
        /* PT4 query to get icon */    
        {       
            // name       
            "icon",          
            // description_for_editor       
            "Poker Tracker auto-rate icon code",        
            // query        
            "SELECT val_icon as result \         
            FROM   player \          
            WHERE  id_site = %SITEID% AND \                 
            player_name LIKE '%SCREENNAME%'",       
            // stat_group       
            pt_group_basic  
        }, 
        /* PT4 query to get number of hands in the database */  
        {       
            // name         
            "hands",
            ...

After the coding work has been done you need to compile the DLL and put
it together with the linker-file (\*.lib) into the OpenHoldem directory
and everything will work automatically: querying the database, accessing
the values in your bot-logic, correct update delays, even the
symbol-descriptions in the formula-editor. Despite of its simplicity
this approach has some more benefits:

- it is update-safe. If a new version of OpenHoldem gets released your
  DLL will work as before without you having to compile a modified
  version of OpenHoldem or missing important bug-fixes.

- you can add stats without having to wait for new releases.

- you can easily contribute to make OpenHoldem better for everyone.

If you need more info about PokerTracker stats or some help you will
find it in our PokerTracker sub-forum:
<http://www.maxinmontreal.com/forums/viewtopic.php?f=273> .
