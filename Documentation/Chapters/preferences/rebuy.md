# OpenHoldem Preferences - Rebuy

Rebuy preferences control when and how OpenHoldem executes the external
rebuy-script. See the section about Automation for more information.

<figure>
<img src="Images/preferences_rebuy.jpg" />
</figure>

- *Change in handnumber:* This option will cause OpenHoldem to wait at
  least for a new hand before doing a second rebuy. It is a simply
  sanity-check to prevent too many rebuys, as most casinos will increase
  your balance only after the end of the current hand.

- *No cards:* This option will prevent rebuys as long as you are
  involved in a hand.

- *Heuristic occlusion check:* Rebuys are especially volatile against
  misscrapes of the balance, which could be caused e.g. by temporary
  occlusion (The truths is: OpenHoldem will keep the last known balance,
  if it can’t scrape the balance correctly. But it’s always good to have
  another safety-net, isn’t it?). The option to do heuristic occlusion
  checks will cause OpenHoldem to look at other players names and
  balances to guess, if heros balance is occluded. In case of a probable
  occlusion the rebuy-process won’t be started. Heuristic occlusion
  checks will add some extra safety, but they won’t catch every
  misscrape; e.g. the very unfortunate case of a partial occluded, but
  non-zero balance will still get accepted.

- *Minimum time to next rebuy:* This option is another sanity check to
  prevent to much rebuys in a short period of time. The time difference
  gets specified in seconds.

- *Rebuy-script:* This is the path to the external script that will be
  launched when a rebuy is required.
