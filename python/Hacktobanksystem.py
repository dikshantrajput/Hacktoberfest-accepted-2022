import random


print('RBI BANK  MAI  AAPKA  SWAAGAT  HAI')
data = []
id = 1
aa = True
while(aa):
    ab = int(input('Which side you want to go? \n1.User side \n2.Admin side \n3.Exit \n '))
    # user side
    if(ab == 1):
        bb = True
        while(bb):
            ac = int(input('What do you want to do? \n1.Register \n2.Login \n3.Exit \n '))
            # 1. Register
                    # enter username = vijay
                    # enter number = 8989898899
                    # tmp = [1,'vijay',8989898899,'pending','','',0,[]]
                    # data.append(tmp)
                    # Registeration Successfully.
            if(ac == 1):
                cc = True
                while(cc):
                    name = input('Enter Username')
                    num = int(input('Enter Number'))
                    status = 'pending'
                    balance = str(0)
                    accountnum = ''
                    password = ''
                    history = []
                    rt = [id, name , num , status , accountnum , password , 0 , history ]
                    data.append(rt)
                    id += 1

                    print('Registration done successfully \n')
                    for i in range(len(data)):
                        print(data[i][0], '-' ,data[i][1], '-' ,data[i][2], '-' ,data[i][3], '-' ,data[i][4], '-' ,data[i][5], '-' ,data[i][6], '-' ,data[i][7])
                    
                    za = int(input('Do you want to add any other data? \n1. Yes \n2. No \n'))
                    if(za == 2):
                        cc = False

            # login
            elif(ac ==2):
                dd = True
                while(dd):
                    gg = input('Enter Username')
                    kl = 'white'
                    for i in range(len(data)):

                        if(gg == data[i][1]):
                            kl = 'green'
                            print('username exists')

                    if( kl == 'white'):
                        print('username doesnot exists')

                    if (data[i][3] == 'approved' ):
                        for k in range(len(data)):
                            ll = int(input('Enter account number'))
                           
                            if(ll == data[k][4]):
                                print('Correct account number')  
                        if(ll != data[k][4]):
                            print('Wrong account number')

                            kk = int(input('Enter password'))
                           
                            if(kk == data[k][5]):
                                print('Correct password')  
                        if(kk != data[k][5]):
                            print('Wrong password')
                                    
                            
                    jn = int(input(' Do u want to again check the username? \n1. Yes \n2. No'))
                    if(jn == 2):
                        dd = False
                            
            # exit
            elif(ac == 3):   
                hh = int(input('Do you want to stay in user side? \n1.Yes \n2.No \n'))
                if(hh == 2):
                    bb = False                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               

    # admin side
    elif(ab == 2):
        ds = True
        while(ds):
        
            jc = int(input('What do you want to do? \n1.Manage user \n2. User wise history \n3.Exit \n '))
            if(jc == 1):
                for i in range(len(data)):
                    if(status == 'pending'):
                        print(data[i][0], '-' ,data[i][1], '-' ,data[i][2], '-' ,data[i][3], '-' ,data[i][4], '-' ,data[i][5], '-' ,data[i][6], '-' ,data[i][7])

                        cf = True
                        while(cf):        
                            hj = int(input('Enter user id to approve'))
                            jl = 'white'
                            for j in range(len(data)):

                                if(hj == data[j][0]):
                                    jl = 'green'
                                    data[j][3] = 'approved'
                                    data[j][4] = random.random() * 10000000000000000
                                    print(int(data[j][4]))
                                    data[j][5] = random.random() * 1000000
                                    print(int(data[j][5]))
                                    print('status approved successfully')

                            if( jl == 'white'):
                                print('status not approved')

                            bg = int(input('Want to approve any other id? \n1.Yes \n2.No \n'))
                            if(bg == 2):
                                cf = False

            fh = int(input('Want to stay in manage user section ? \n1.Yes \n2.No \n'))
            if(fh == 2):
                ds = False

    # exit
    elif(ab == 3):
        ii = int(input('Do you want to stay in our bank? \n1.Yes \n2.No \n'))
        if(ii == 2):
            aa = False  