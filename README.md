# The Floor Is Lava!
A 2D platforming game written in C++ using SFML


## Development
  * This was created in Visual Studio so it has the solution .sln file and other VS config files in the repository.
  
### Windows
  * This repo does not have the necessary environment setup for SFML
  * download SFML:
    - SFML downloaded and extracted somewhere on your dev machine
      - download [here](https://www.sfml-dev.org/download/sfml/2.4.2/). select 'Visual C++ 14 (2015) - 32-bit' option
      - extract zip file
      - move extracted folder somewhere appropriate (I moved it to 'C:\Program Files (x86)\' and renamed it to just 'SFML')
    
  * Tell project where SFML is:
    - Clone this repo to wherever you store you projects and open the solution in Visual Studio
    - Then, once the project is opened, in the top menu bar navigate to these settings and set this boxes to:
      - Project > Properties > C/C++ > General > Additional Include Libraries: <path-to-your-sfml-folder>\include
      - Project > Properties > Linker > General > Additional Library Directories: <path-to-your-sfml-folder>\lib
      - Project > Properties > Linker > Input   Add this text to the very beginning of the text box without overwriting what is already in there:
          
            sfml-graphics-d.lib;sfml-window-d.lib;sfml-system-d.lib;sfml-network-d.lib;sfml-audio-d.lib;
    
  * Copy SFML dll's to projects source code
    - go to where you saved the SFML folder and open it then open the 'bin' folder
    - copy all files in this folder and paste them in the same place as the game's source code files

* Then in Visual Studio the game should build and run


### Non-Windows OS's
  * This setup will not be the same as Windows.
    - for other OS's you can delete the Visual Studio config files:
      * floor-is-lava.sln
      * floor-is-lava.vcxproj
      * floor-is-lava.vcxproj.filters
  
  * go through SFML setup for your specific OS to make sure SFML is available to the games source files
  
  * IMPORTANT: Windows and MacOs/Linux represent new lines differently. Windows uses a carriage return AND a line feed character while MacOs/Linux just us a line feed. The .gitattribute file takes care of this if you edit files on a Mac/Linux machine using only line feeds. So if you make changes not using git you need to set your editor to CRLF for new lines.
