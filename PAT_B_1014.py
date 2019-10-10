weekday_dict={'A':'MON','B':'TUE','C':'WED','D':'THU','E':'FRI','F':'SAT','G':'SUN'}
hour_dict = {'0':'00','1':'01','2':'02','3':'03','4':'04','5':'05','6':'06','7':'07','8':'08','9':'09','A':'10','B':'11','C':'12','D':'13','E':'14','F':'15','G':'16','H':'17','I':'18','J':'19','K':'20','L':'21','M':'22','N':'23'}
data_list = []
for k in range(4):
  data_list.append(input())
cnt = 0
for i in range(len(data_list[0])):
    if cnt == 1:
        if data_list[0][i] == data_list[1][i]:
            if data_list[0][i] in hour_dict:
                hour = hour_dict[data_list[0][i]]
                break

    if cnt == 0:
        if data_list[0][i] == data_list[1][i] and data_list[0][i].isalpha() and data_list[0][i].isupper():
            weekday = weekday_dict[data_list[0][i]]
            cnt = 1

for j in range(len(data_list[2])):
    if data_list[2][j] == data_list[3][j] and data_list[2][j].isalpha() and data_list[2][j].islower():
        min = j
        break
print(weekday+' '+hour+':'+'%02d'%min)