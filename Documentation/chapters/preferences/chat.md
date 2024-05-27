# OpenHoldem Preferences – Chat

Chat preferences control how the OpenHoldem’s Chat feature in the
Autoplayer functions. See the {f\$chat} section for more information.
The chat feature will generate a message if the f\$chat-function returns
non-zero and the safety-delays are passed.

<figure>
<img src="Images/preferences_chat.JPG" />
</figure>

- *Minimum delay*: This is the minimum amount of time that Chat will
  wait (in seconds) between the posting of messages to the chat box on
  the Casino client. This is a safety feature and is present to prevent
  accidental spamming of the chat box. Feel free to set this to “1” if
  you are overly confident in your configuration skills.

- *Random delay*: In addition to the “Minimum delay”, the amount of time
  specified in this parameter (in seconds) will be used to randomly
  delay the entry of a chat message into the chat box. The setting here
  is the maximum amount of random delay.
