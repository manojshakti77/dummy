::Provides the title for the Window
TITLE MANOj_FILES  

::Turns of the verbose of command execution
ECHO OFF

::Printing the things on the screen
ECHO "Copying the Things"

::Mounting the remote directory 
pushd \\rmnbpt.rmnus.sen.symantec.com\results\NB\2017_03\413158\PACKAGES

::Copying the things from mounted remote directory(provide options /y /E /i to copy the folders & some other options)
xcopy CD D:\BPT_Builds\temp\

::Unmounting the Remote directory
popd  

::Pausing the execution to expect the input from the user for further execution
PAUSE

::command to copy the files or folders from local directory
copy /source /destination

:: START is the command to execute any .exe file 
START chrome

::http://www.technicalnotes.org/how-to-write-a-batch-bat-file-step-by-step-guide-to-create-batch-file/
::http://superuser.com/questions/367929/xcopy-deletes-destination-folder-and-copies-0-files
::http://www.computerhope.com/forum/index.php?topic=32804.0