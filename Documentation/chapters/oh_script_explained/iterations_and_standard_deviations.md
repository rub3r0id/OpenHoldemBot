# Iterations and Standard Deviation

Running AA headsup preflop with X iterations in OpenHoldem to determine
the standard deviation in prwin for the various numbers of iterations.
Here are the results:

<figure>
<img src="Images/Nit_chart1.png" />
</figure>

Here is how to use the data in the above graphs:

1.  Decide what error you find acceptable 99% of the time. For example,
    if you are happy with getting prwin’s of 0.846 - 0.852 99% of the
    time for AA headsup preflop, your error would be (0.849) +- 0.003.

2.  That error is standard deviations. To get 1 standard deviation,
    divide by 3 (to give std. dev. = 0.001).

3.  Find that standard deviation in the top chart and read off the
    number of iterations required. In our case, it would be 100,000
    required iterations.

<figure>
<img src="Images/Nit_chart2.png" />
</figure>

The prwin values you obtain will be within 1 standard deviation 67% of
the time, within 2 standard deviations 95% of the time, and within 3
standard deviations 99% of the time.
