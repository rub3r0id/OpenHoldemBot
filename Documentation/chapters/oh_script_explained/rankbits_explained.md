# Rankbits explained

OpenHoldem uses the following method to classify a group of cards
according to rank within a single value. Note that if an ace is present
then both the 14 bit and the 1 bit will be set.

<figure>
<img src="images/Rankbits.gif" />
<figcaption>Rank bits</figcaption>
</figure>

| Bit | Meaning    | Decimal value |
|:----|:-----------|--------------:|
|     | not used   |         32768 |
|     | Ace (high) |         16384 |
|     | King       |          8192 |
|     | Queen      |          4096 |
|     | Jack       |          2048 |
|     | Ten        |          1024 |
|     |            |           512 |
|     |            |           256 |
|     |            |           126 |
|     |            |            64 |
|     |            |            32 |
|     |            |            16 |
|     |            |             8 |
|     |            |             4 |
|     | Ace (low)  |             2 |
|     | not used   |             1 |

![image](images/rankbits_manualmode.jpg)

In this example rankbits is 20518 (decimal), which is 0b101000000100110
(binary)

    101000000100110
    A-Q------5--2A-

A quick calculation will verify that 20518 is the sum of the card-values
in the table above:

| Ace (high)     | 16384 |
|:---------------|------:|
| Queen          |  4096 |
| Five           |    32 |
| Two            |     4 |
| Ace (low)      |     2 |
| rankbits (sum) | 20518 |

Now a quick check, if an ace is on the board:

    ##f$ace_on_the_board##
    (rankbitscommon & 0x4000) != 0

This code will just execute a bit-wise AND-operation of the ACE-high-bit
and then check if the result is non-zero, i.e ace present. 0x4000 is the
hexadecimal representation of 0b0010000000000000, that’s just more easy
to write and read than plain binary, and very easy to transform.

If you have never worked with binary numbers before – don’t get
confused. Just try out MicroSofts calculator and select scientif view.
Things will become easy.
