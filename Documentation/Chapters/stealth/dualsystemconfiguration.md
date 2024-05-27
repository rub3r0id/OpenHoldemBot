# OpenHoldem Dual System Configuration 

In this scenario, the poker client software resides on “System A”, and
the OpenHoldem software resides on “System B”. As the OpenHoldem
software resides on a wholly different machine than the poker software,
less thought needs to be given to protecting detection of the OpenHoldem
software. OpenHoldem connects to the poker client windows using the
Bring software as an intermediary. It should be obvious, but in order to
make this scenario work, you either need two physical machines or two
virtual machines. Rootkits still may be needed to obscure the network
ports and traffic between the two systems.
