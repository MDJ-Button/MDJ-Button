from urllib.request import urlopen

def GetFile(TheLink):
        data = urlopen(TheLink, timeout=10).read().decode('utf_8')
        return data;
        
        
    

