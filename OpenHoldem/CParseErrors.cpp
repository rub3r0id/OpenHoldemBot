//******************************************************************************
//
// This file is part of the OpenHoldem project
//    Source code:           https://github.com/OpenHoldem/openholdembot/
//    Forums:                http://www.maxinmontreal.com/forums/index.php
//    Licensed under GPL v3: http://www.gnu.org/licenses/gpl.html
//
//******************************************************************************
//
// Purpose:
//
//******************************************************************************

#include "stdafx.h"
#include "CParseErrors.h"

#include "CFormulaParser.h"
#include "CTokenizer.h"
#include "WindowFunctions/window_functions.h"
#include "StringFunctions/string_functions.h"
#include "TokenizerConstants.h"

bool CParseErrors::_is_error = false;
CString CParseErrors::_last_error_message = "";

void CParseErrors::Error(CString short_message) {
  if (short_message.Right(1) != "\n") {
    short_message += "\n";
  }
  CString message;
  message.Format("%s%s%s%s%s%s%s%i%s%s%i%s%s%s%s%s%s%s%s%s",
    "Error: ", short_message,
    "==============================================\n",
    "Function: ", CTokenizer::CurrentFunctionName(), "\n",
    "Line absolute: ", CTokenizer::LineAbsolute(), "\n",
    "Line relative: ", CTokenizer::LineRelative(), "\n",
    "File: ", CTokenizer::InputFile(), "\n",
    "==============================================\n",
    "\n",
    ErroneousCodeSnippet(), "\n",
    "==============================================\n");
  // Avoid duplicate messages, wqhich might be generated by the parser 
  // or by the tokenizer (if a char gets checked multiple times)
  if (_last_error_message == message) {
    return;
  }
  MessageBox_Interactive(message, "Parse Error", 0);
  _last_error_message = message;
}

void CParseErrors::ErrorUnknownIdentifier(CString name) {
  CString message;
  message.Format("Unknown identifier: %s", name);
  Error(message);
}

void CParseErrors::UnexpectedToken(CString short_error_message, CString expected, int token_found_instead) {
  CString message;
  message = short_error_message + expected;
  message += "Found: " + TokenVerboseExplained(token_found_instead) + "\n";
  Error(message);
}

CString CParseErrors::ErroneousCodeSnippet() {
  // We have seen functions up to several 1000 lines 
  // (insane Shanky-style) and lines up 5000 characters
  // (auto-generated code).
  // Here we want to build some code-snippet 
  // that fits into a message-box. ;-)
  const int kLinesOfCodeToShow = 5;
  const int kMaxCharactersPerLineToShow = 60;
  char* remaining_input = CTokenizer::RemainingInput();
  if (remaining_input == NULL) return "";
  CString erroneous_code_snippet = "";
  for (int i = 0; i < kLinesOfCodeToShow; i++) {
    for (int j = 0; j < kMaxCharactersPerLineToShow; j++) {
      char next_character = remaining_input[j];
      erroneous_code_snippet += next_character;
      if (next_character == '\n') {
        // End of line reached
        // Therefore terminate this line early
        break;
      }
      else if (next_character == '\0') {
        // End of function reached
        // Therefore terminate completely
        goto EndOfOuterLoop;
      }
    }
    if (RightCharacter(erroneous_code_snippet) != '\n') {
      erroneous_code_snippet += '\n';
    }
    // Skip to end of line 
    char next_character;
    do {
      next_character = *remaining_input;
      remaining_input++;
    } while ((next_character != '\n') && (next_character != '\0'));
    if (next_character == '\0') {
      // End of input reached
      // Can't continue with the for-loop
      break;
    }
	}
EndOfOuterLoop:
  return erroneous_code_snippet;
}

void CParseErrors::ClearErrorStatus() {
  _is_error = false;
  _last_error_message = "";
} 

bool CParseErrors::AnyError() {
  return _is_error;
}

void CParseErrors::MessageBox_Formula_Error(CString Message, CString Title) {
  // Make sure, that we have a line-break at the end.
  if (Message.Right(1) != "\n") {
    Message += "\n";
  }
  if (p_formula_parser->IsParsing()) {
    CParseErrors::Error(Message);
  }
  else {
    MessageBox_Error_Warning(Message, Title);
  }
}