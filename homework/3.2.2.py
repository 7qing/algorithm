import re

# 函数：检查密码是否有效
def is_valid_password(password):
    """检查密码是否符合要求"""
    if (6 <= len(password) <= 12 and                     # 检查密码长度
        re.search("[a-z]", password) and                 # 至少有一个小写字母
        re.search("[A-Z]", password) and                 # 至少有一个大写字母
        re.search("[0-9]", password) and                 # 至少有一个数字
        re.search("[$#@]", password)):                   # 至少有一个特殊字符
        return True
    return False

# 函数：处理输入和输出有效密码
def check_passwords(passwords):
    """检查逗号分隔的密码，并返回符合条件的密码"""
    # 将输入的字符串按逗号分隔成列表
    password_list = passwords.split(',')
    
    # 使用列表推导式筛选有效密码
    valid_passwords = [password for password in password_list if is_valid_password(password)]
    
    # 返回符合条件的密码，用逗号分隔
    return ','.join(valid_passwords)

# 主程序
def main():
    # 输入一系列逗号分隔的密码
    input_passwords = input("请输入一系列逗号分隔的密码： ")
    
    # 检查并输出符合条件的密码
    result = check_passwords(input_passwords)
    
    # 打印符合条件的密码
    print("符合条件的密码为：", result)

if __name__ == "__main__":
    main()
