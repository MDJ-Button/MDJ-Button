from urllib.request import urlopen

def FileExists(TheLink):
    try:
        urlopen(TheLink, timeout=10).read().decode('utf_8')
        return "file_found";
    except:
        return "file_not_found";