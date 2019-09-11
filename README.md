# CPSC230
LCC Algorithms &amp; Computing w/ C++. This is the repo used by Stefan Carlson for all the programs written for the class

## Project Structure
Each assignment, be it a lab or homework, is a single project. Within each project are potentially multiple source files. **These files are unrelated and independent programs**. Due to the fact that all programs written for the class are to be turned in as single .cpp files, this is how I have chosen to structure my workspace. The currently active program within any given project is the one whose main functin is actually called `main`, not some variation such as `main1`. These variations are purely to make the linker happy, however, and are not reflected in the source files being turned in.

### Code style
Code is formatted according to the [Linux Kernel Style](https://www.kernel.org/doc/html/latest/process/coding-style.html), a slight modification of the style of the prohpets, Keninghan & Ritchie. I use it because, in Linus Torvald's own words, "(a) K&R are **right** and (b) K&R are right."

### IDE
Technically, the official IDE for the class is Microsoft Visual Studio 2017 Community Edition, but due to my strong preference for Eclipse, most of the projects are Eclipse projects. The stray VS Projects are due to the class's preference for Microsoft's IDE.
