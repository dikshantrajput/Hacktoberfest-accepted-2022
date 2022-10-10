## Text to Speech (Speech Synthesis)
A Text-to-Speech Web App that does vocal narration of text displayed on screen in real time built using JavaScript's Web Speech API. SpeechSynthesis interface was used that allows programs to read out their text content (normally via the device's default speech synthesizer.)

The site is live at : https://text2speeches.netlify.app/

<a target="_blank" href="https://text2speeches.netlify.app/">
          <img src="https://github.com/rahulkarda/Text-to-Speech/blob/main/images/text2speeches.jpg?raw=true" width="100%" alt="Text To Speech Converter"/>
</a>
<br>

## Tech Stack
![](https://img.shields.io/badge/Code-HTML5-informational?style=flat&logo=html5&logoColor=white&color=brightgreen)
![](https://img.shields.io/badge/Code-CSS3-informational?style=flat&logo=css3&logoColor=white&color=brightgreen)
![](https://img.shields.io/badge/Code-JavaScript-informational?style=flat&logo=javascript&logoColor=white&color=brightgreen)
![](https://img.shields.io/badge/Code-Bootstrap-informational?style=flat&logo=bootstrap&logoColor=white&color=brightgreen)

[Bootstrap](https://getbootstrap.com/) is a free and open-source CSS framework directed at responsive, mobile-first front-end web development.

[Web Speech API](https://developer.mozilla.org/en-US/docs/Web/API/Web_Speech_API) enables you to incorporate voice data into web apps. The Web Speech API has two parts: SpeechSynthesis (Text-to-Speech), and SpeechRecognition (Asynchronous Speech Recognition.). SpeechSynthesis interface allows programs to read out their text content (normally via the device's default speech synthesizer.)

## Interface Used
  <h3>Speech Synthesis</h3>
    
  1. SpeechSynthesis - The controller interface for the speech service; this can be used to retrieve information about the synthesis voices available on the device,        start and pause speech, and other commands besides.
  2. SpeechSynthesisUtterance - Represents a speech request. It contains the content the speech service should read and information about how to read it (e.g.              language, pitch and volume.)
  3. SpeechSynthesisVoice - Represents a voice that the system supports. Every SpeechSynthesisVoice has its own relative speech service including information about          language, name and URI.
  4. Window.speechSynthesis - Implemented by the Window object, which returns a SpeechSynthesis object, which is the entry point into using Web Speech API speech            synthesis functionality.

## Optimizations
While improve this project, I would start by implementing the following features -

   1. Adding support for more languages  
   2. Adding more voice types
              
## Lessons Learned
My learning was focused on making the use of Web Speech API and to create a simple UI where user can type some text and start Speech Synthesis to convert the text to speech and narration options with different voice types. I learned how the Web Speech API works and differnece between SpeechSynthesis (Text-to-Speech), and SpeechRecognition (Asynchronous Speech Recognition.).











