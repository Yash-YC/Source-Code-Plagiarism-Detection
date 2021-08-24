#!/usr/bin/python

f =open("test");

T=int(f.readline());

for k in range(0,T):

	l=f.readline().split();

	N=int(l[0]);
	M=int(l[1]);

	map=[];
	tovisit=[]
	for i in range(0,N):
		map.append([]);
		l=f.readline().split();
		for j in range(0,M):
			data=[0,0,0]
			data[0]=int(l[j*3+0]);
			data[1]=int(l[j*3+1]);
			data[2]=int(l[j*3+2]);
			#Normalize the start
			data[2]%=(data[0]+data[1])
			map[-1].append((data,[1000000,1000000,1000000,1000000]));

	tovisit.append(((N-1),0))
	map[N-1][0][1][3]=0
	#Alg
	while len(tovisit):
		pos=tovisit.pop();
		sem=map[pos[0]][pos[1]][0];
		data=map[pos[0]][pos[1]][1];
		cycle=sem[0]+sem[1];
		if(data[0]!=1000000):
			if pos[0]!=0 :
				if(data[0]+2<map[pos[0]-1][pos[1]][1][3]):
					map[pos[0]-1][pos[1]][1][3]=data[0]+2;
					tovisit.append((pos[0]-1,pos[1]));
			if pos[1]!=0:
				if data[0]+2<map[pos[0]][pos[1]-1][1][1]:
					map[pos[0]][pos[1]-1][1][1]=data[0]+2;
					tovisit.append((pos[0],pos[1]-1))

			tempo=(data[0]+cycle-sem[2])%cycle;
			if tempo<sem[0]:
				tn=data[0]+1;
				tw=data[0]+(cycle-tempo)+1;
			else:
				tn=data[0]+(cycle-tempo)+1;
				tw=data[0]+1;
			if tn<data[3]:
				data[3]=tn;
				tovisit.append(pos);

			if tw<data[1]:
				data[1]=tw;
				tovisit.append(pos);

		if(data[1]!=1000000):
			if pos[0]!=0:
				if data[1]+2<map[pos[0]-1][pos[1]][1][2]:
					map[pos[0]-1][pos[1]][1][2]=data[1]+2;
					tovisit.append((pos[0]-1,pos[1]));
			if pos[1]!=(M-1):
				if data[1]+2<map[pos[0]][pos[1]+1][1][0]:
					map[pos[0]][pos[1]+1][1][0]=data[1]+2;
					tovisit.append((pos[0],pos[1]+1))

			tempo=(data[1]+cycle-sem[2])%cycle;
			if tempo<sem[0]:
				tn=data[1]+1;
				tw=data[1]+(cycle-tempo)+1;
			else:
				tn=data[1]+(cycle-tempo)+1;
				tw=data[1]+1;
			if tn<data[0]:
				data[0]=tn;
				tovisit.append(pos);

			if tw<data[2]:
				data[2]=tw;
				tovisit.append(pos);

		if(data[2]!=1000000):
			if pos[0]!=(N-1):
				if data[2]+2<map[pos[0]+1][pos[1]][1][1]:
					map[pos[0]+1][pos[1]][1][1]=data[2]+2;
					tovisit.append((pos[0]+1,pos[1]));
			if pos[1]!=(M-1):
				if data[2]+2<map[pos[0]][pos[1]+1][1][3]:
					map[pos[0]][pos[1]+1][1][3]=data[2]+2;
					tovisit.append((pos[0],pos[1]+1))

			tempo=(data[2]+cycle-sem[2])%cycle;
			if tempo<sem[0]:
				tn=data[2]+1;
				tw=data[2]+(cycle-tempo)+1;
			else:
				tn=data[2]+(cycle-tempo)+1;
				tw=data[2]+1;
			if tn<data[1]:
				data[1]=tn;
				tovisit.append(pos);

			if tw<data[3]:
				data[3]=tw;
				tovisit.append(pos);

		if(data[3]!=1000000):
			if pos[0]!=(N-1) :
				if data[3]+2<map[pos[0]+1][pos[1]][1][0]:
					map[pos[0]+1][pos[1]][1][0]=data[3]+2;
					tovisit.append((pos[0]+1,pos[1]));
			if pos[1]!=0:
				if data[3]+2<map[pos[0]][pos[1]-1][1][2]:
					map[pos[0]][pos[1]-1][1][2]=data[3]+2;
					tovisit.append((pos[0],pos[1]-1))

			tempo=(data[3]+cycle-sem[2])%cycle;
			if tempo<sem[0]:
				tn=data[3]+1;
				tw=data[3]+(cycle-tempo)+1;
			else:
				tn=data[3]+(cycle-tempo)+1;
				tw=data[3]+1;
			if tn<data[0]:
				data[0]=tn;
				tovisit.append(pos);

			if tw<data[2]:
				data[2]=tw;
				tovisit.append(pos);
	print "Case #"+str(k+1)+": "+str(map[0][M-1][1][1])
