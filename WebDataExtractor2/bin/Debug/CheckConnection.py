from urllib.request import urlopen

def CheckConnection(TheLink):
    try:
        urlopen(TheLink, timeout=10)
        return "have_connection";
    except:
        return "no_connection";
    


