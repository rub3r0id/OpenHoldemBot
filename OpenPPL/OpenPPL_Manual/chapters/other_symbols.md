# Other Symbols

<table>
<thead>
<tr class="header">
<th style="text-align: left;">Name</th>
<th style="text-align: left;">Meaning</th>
<th style="text-align: left;">Limitations</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td style="text-align: left;">IsFinalTable</td>
<td style="text-align: left;">We are at the final table of a
tournament</td>
<td style="text-align: left;">Works only with OpenHoldem 2.2.0.+ and at
casinos where the final table and normal tables can be visually
distinguised. See the tablemap-symbol s$isfinaltable.</td>
</tr>
<tr class="even">
<td style="text-align: left;">Others</td>
<td style="text-align: left;"><p>Always true - mainly used for</p>
<pre><code>When Others Fold Force</code></pre></td>
<td style="text-align: left;">None</td>
</tr>
<tr class="odd">
<td style="text-align: left;">Random</td>
<td style="text-align: left;">Returns a random number in the range
<span>[</span>0..100<span>]</span></td>
<td style="text-align: left;"><p>Gets evaluated new each time it gets
used. So be careful if you code sequences of random actions. If you need
a random function that stays constant for some time you could use the
OpenHoldem symbols</p>
<ul>
<li><p>randomheartbeat</p></li>
<li><p>randomround</p></li>
<li><p>randomround1..randomround4</p></li>
<li><p>randomhand</p></li>
</ul>
<p>But be careful: OpenHoldems random symbols are in the range
<span>[</span>0..1<span>]</span></p></td>
</tr>
</tbody>
</table>
