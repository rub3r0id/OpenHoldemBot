# Using prw1326

Included in the attachment is a library for prwin1326, it includes
functions to set hands, manage weights, log prw1326 lists. Now i will
not go into details to much simply take a look at the example below:

This is the main part of the code for this example:

    double process_state(holdem_state* pstate) 
    {    
        if(pstate!=NULL)       
            m_holdem_state[ (++m_ndx)&0xff ] = *pstate;
    /////////////////////////////////////////////////////    
    //ACTIVATING PRW    
    /////////////////////////////////////////////////////    
        prw1326->preflop = 1326;    
        prw1326->useme = 1326;
    /////////////////////////////////////////////////////    
    //PRW EXAMPLE    
    /////////////////////////////////////////////////////    
        int betround = (int)gws("betround");    
        int userchair = (int)gws("userchair");    
        int handnumber = (int)gws("handnumber");    
        int ismyturn = (int)gws("ismyturn");
        if(ismyturn) {       
            //list managment preflop       
            if(betround == 1 && round_trigger != betround) {          
                //chair 0 -> VIP 50% PFR 10%          
                prw_set_preflop_list(0, 0.5, 0.1, 1024);          
                //chair 1 -> VIP 20% PFR 10%          
                prw_set_preflop_list(1, 0.2, 0.1, 1024);
                //log preflop handranges          
                prw_log_handlist(handnumber, userchair, betround, 0);
                round_trigger = betround;       
            }       
            //list managment flop       
            if(betround == 2 && round_trigger != betround)       
            {
                //chair 0 -> remove all pocket pairs          
                for(int i=0; i<13; i++)             
                prw_remove_pp(0, i, 1024);          
                //chair 1 -> remove all suited aces          
                for(int i=0; i<13; i++)             
                prw_remove_s(1, 12, i, 1024);
                //log flop handranges          
                prw_log_handlist(handnumber, userchair, betround, 1);
                round_trigger = betround;       
            }    
        }
        return 0; 
    }

All this piece of code does is:

1.  set up hand range for chair 0 which include 50% of the best hands
    and exclude 10% of the best hands, same for chair 1 with 20% and 10%

2.  on the flop it removes pocket pairs out of chair 0’s range and
    suited aces out of chair 1’s range

3.  creates a log file preflop

4.  creates a log file on the flop

The log files are saved in C:/prwlog/handnumber/ folder, this is how the
log files look like, once they have been converted with gnuplot into
images:

![image](images/suitlog_chair0_round1_logparam0_suitlog_0.jpg)

This is a log of all 1326 hands, on the top left are the suited hands on
the bottom right are the unsuited hands.

![image](images/suitlog_chair0_round1_logparam0_suitlog_1.jpg)

![image](images/suitlog_chair0_round1_logparam0_suitlog_2.jpg)

These 2 are 2 out of 10 more logs seperated by all suit combinations.
Now to obtain these log pics you need gnuplot, as the DLL saves a
gnuplot script in the log folder which needs to be executed to create
those images. it is pretty simple:

1.  download gnuplot: <http://www.gnuplot.info/> .

2.  install and run gnuplot

3.  open the log folder C:/prwlog/handnumber/gnuscript/ there, if you
    ran this DLL (vs 2 opponents ideally in chair 0 & 1), you should
    find 2 files which have the name gnuscript-0 (preflop log) and
    gnuscript-1 (flop log) you can simple drag them to the gnuplot
    window or simply select file -\> open and browse to their location.

4.  if you execute them it may take a while till the jpgs are created in
    the directory because these are height projections of 3d plots and
    depending on your CPU this can take some minutes.

you can also set the resolution lower if it takes to long. look for this
line in prw_log.h:

    gnuplot_obj << "set dgrid3d 500,500,1" << endl;

Replace the 500,500 values with lower one.

## File

The files for this tutorial can be found here:

- <http://www.maxinmontreal.com/forums/download/file.php?id=2338>

- <http://www.maxinmontreal.com/forums/download/file.php?id=2337>
