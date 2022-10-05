def create_matrix(key):
    letters=[chr(i) for i in range(ord('A'),ord('Z')+1)]
    final=list()
    for k in key:
        if k not in final:
            if (k=='J'):
                final.append('I')
            else:
                final.append(k)
    flag=0
    for i in range(ord('A'),ord('Z')+1):
        if chr(i) not in final:
            if i==ord('I') and 'J' not in final:
                final.append('I')
                flag=1
            elif flag==0 and i==ord('I') or i==ord('J'):
                pass    
            else:
                final.append(chr(i))
    
    matrix=[[' ' for i in range(5)] for j in range(5)]
    k=0
    for i in range(5):
        for j in range(5):
            matrix[i][j]=final[k]
            k+=1
    return matrix

def position(x,matrix):
    pos=[]
    if x=='J':
        x='I'
    for i ,j in enumerate(matrix):
        for k,l in enumerate(j):
            if x==l:
                pos.append(i)
                pos.append(k)
                return pos
    
def encrypt_playfair(ptxt,key):
    ctxt=""
    key_matrix=create_matrix(key)
    for s in range(0,len(ptxt)+1,2):
        if s<len(ptxt)-1:
            if ptxt[s]==ptxt[s+1]:
                ptxt=ptxt[:s+1]+'X'+ptxt[s+1:]
    if len(ptxt)%2!=0:
        ptxt=ptxt[:]+'X'
    
    i=0
    while i<len(ptxt):
        pos=[]
        pos=position(ptxt[i],key_matrix)
        pos1=[]
        pos1=position(ptxt[i+1],key_matrix)
        if pos[1]==pos1[1]:
            ctxt+=key_matrix[(pos[0]+1)%5][pos[1]]
            ctxt+=key_matrix[(pos1[0]+1)%5][pos1[1]]+' '
        elif pos[0]==pos1[0]:
            ctxt+=key_matrix[pos[0]][(pos[1]+1)%5]
            ctxt+=key_matrix[pos1[0]][(pos1[1]+1)%5]+' '
        else:
            ctxt+=key_matrix[pos[0]][pos1[1]]+key_matrix[pos1[0]][pos[1]]+' '    
        i+=2
    return ctxt

def decrypt_playfair(ctxt,key):
    ptxt=""
    key_matrix=create_matrix(key)
    i=0
    while i<len(ctxt):
        pos=[]
        pos=position(ctxt[i],key_matrix)
        pos1=[]
        pos1=position(ctxt[i+1],key_matrix)
        if pos[1]==pos1[1]:
            ptxt+=key_matrix[(pos[0]-1)%5][pos[1]]
            ptxt+=key_matrix[(pos1[0]-1)%5][pos1[1]]
        elif pos[0]==pos1[0]:
            ptxt+=key_matrix[pos[0]][(pos[1]-1)%5]
            ptxt+=key_matrix[pos1[0]][(pos1[1]-1)%5]
        else:
            ptxt+=key_matrix[pos[0]][pos1[1]]+key_matrix[pos1[0]][pos[1]]    
        i+=2
    return ptxt

#main function for menu driven program

def main():
    print("_-_-_-_-_-_-_-_-_ PLAYFAIR CIPHER _-_-_-_-_-_-_-_-_")
    ch="Y"
    while(ch=="Y" or ch=="y"):
        print("\n\t*** MENU PLAYFAIR CIPHER***")
        print("\n1. Encyrption")
        print("2. Decryption\n")
        ans=int(input("\tEnter your choice: "))
        
        if(ans==1):
            key=input("\nEnter the key: ")
            key=key.replace(" ", "")
            key=key.upper()
            input_txt=input("Enter plain text: ")
            input_txt=input_txt.replace(" ", "")
            input_txt=input_txt.upper()
            print("\nPLAIN TEXT:",input_txt)
            print("CIPHER TEXT:",encrypt_playfair(input_txt,key))
        elif(ans==2):
            key=input("\nEnter the key: ")
            key=key.replace(" ", "")
            input_txt=input("Enter cipher text: ")
            input_txt=input_txt.replace(" ", "")
            print("\nCIPHER TEXT:",input_txt)
            print("PLAIN TEXT:",decrypt_playfair(input_txt,key))
        else:
            print("\nInvalid option! Try again")
        
        ch=input("\nDo you want to try again? {Y/N}: ")
        print("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*")

main()
