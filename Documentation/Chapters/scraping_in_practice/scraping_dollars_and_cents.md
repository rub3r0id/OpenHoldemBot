# Scraping Dollars and Cents

For s\$ttlimits, s\$ttlimitsX, r\$c0limits/s\$c0limits, and
r\$c0limitsX/s\$c0limitsX regions:

- the dollar sign (\$) leader is recognized and discarded. Commas are
  recognized and discarded.

- the remaining text is then used to generate a floating point number -

- the cent sign (¢) (\*not the letter ’c’) trailer is recognized and
  causes the number to be divided by 100.

- the thousand (k) and million (m) trailers are recognized and causes
  the number to be multiplied by 1000 or 1000000 respectively

<figure>
<img src="images_scraping_dollars_and_cents/344b87l.jpg" />
</figure>
