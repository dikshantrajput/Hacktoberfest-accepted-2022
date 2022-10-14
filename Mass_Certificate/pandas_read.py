import pandas as pd    
def read(d):
    # Read the file    
    data = pd.read_csv(d, low_memory=False)    
    for i in data['Name']:
        print (i)
        
    # Output the number of rows    
    # print("Total rows: {}".format(len(data)))    
        
    # See which headers are available    
    # print(list(data))    
    # print((data.Name[0]))    