import os

# ユーザ指定
USERNAME = "teradatakayuki"
USER = "p4 -u %s info" % (USERNAME)
os.system(USER)

# ユーザ情報と最新のサブミット済チェンジリストのチェンジリスト番号を示す1行の出力
CHANGE_LIST = "p4 changes -m 1 -s submitted"
os.system(CHANGE_LIST)