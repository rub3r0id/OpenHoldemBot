# Chat

OpenHoldem’s chat feature is provided for two reasons: deception and
fun. The key to chat is to use it wisely and to not overdo it.

## OH-Script 

Create a new formula f\$chat with OpenHoldem, which returns 0, if you
wish no chat and one of the constants described below to send a simple
chat message. These constants are not available as OpenHoldem symbols,
you have to use the numerical values (gg=1, nh=2, ...).

## Available chat messages

A complete list of available symbols for formula

    enum { 
        no_simple_Chat = 0, 
        simple_Chat_gg, 
        simple_Chat_nh, 
        simple_Chat_vnh, 
        simple_Chat_n1, 
        simple_Chat_wow, 
        simple_Chat_lol, 
        simple_Chat_rofl, 
        simple_Chat_haha,
        simple_Chat_tu,
        simple_Chat_thx,
        simple_Chat_omg,
        simple_Chat_sick,
        simple_Chat_fu, 
        simple_Chat_fish, 
        simple_Chat_hi, 
        simple_Chat_hello, 
        simple_Chat_bye, 
        // 18 :)
        simple_Chat_happy,
        // 19 :(
        simple_Chat_sad
        // 20: \o/
        // 21: /o\
    };

## OH-Script with DLL 

Simply define f\$chat as dll\$chat and handle this symbol. Return the
same constants as used above to specify the message to send, especially
“no_simple_Chat” to send no message.

## DLL only 

Using Chat in your DLL gives you two additional opportunities: Any chat
message you want At any time

At startup your DLL will receive an additional message
p_send_chat_message, providing a pointer to access the chat function.
The function has the following prototype:

    void SendChatMessage(char* new_message);

Safety measure: To prevent a crazy bot flooding the chat, there are two
settings in {Preferences}:

- Minimum delay (seconds)

- Additional random delay (seconds)

Adjust these to any value you are comfortable with, if you trust your
bot.

## Chat and Table Maps 

In order to use the chat function, OpenHoldem has to know where the chat
box of your casino software is. Therefore the corresponding TableMap has
to specify a region that defines the location of the chat box.
transform.

Without the chat box region, all attempts to chat will be ignored
without any warnings, avoiding anything that could disturb the screen
scraping process.

## Limitations

- One message at a time. There is no waiting list, or queue, to handle
  multiple messages (as we are lazy and assume, there’s no need for too
  much chat at a poker table).

- There is no way to specify any concrete delay. The messages will be
  sent only when {The Autoplayer} is active and there will be an
  additional delay per character, the intent being to simulate
  human-like input.

- Only predefined chat messages if you are not using a DLL.

- No support for non-alpha-numeric-characters.

- On some sites that temporarily block the chat (e.g. Cakepoker),
  multiple chat messages can queue up in the poker client. The obvious
  counter measure would be to always delete the chat box, but that could
  raise a red flag on other sites.
