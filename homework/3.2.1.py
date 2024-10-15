import random
import string

# 函数：生成随机字符串
def generate_random_string(length=8):
    """生成一个由字母和数字组成的随机字符串"""
    letters_and_digits = string.ascii_letters + string.digits
    return ''.join(random.choice(letters_and_digits) for i in range(length))

# 函数：将多个字符串写入文件
def write_strings_to_file(filename, num_strings=10):
    """生成指定数量的字符串，并写入文件"""
    with open(filename, 'w') as file:
        for _ in range(num_strings):
            random_string = generate_random_string()
            file.write(random_string + '\n')

# 函数：读取文件并统计字符串的个数
def count_strings_in_file(filename):
    """读取文件内容，并统计其中的字符串个数"""
    with open(filename, 'r') as file:
        lines = file.readlines()  # 读取所有行
        string_count = len(lines)  # 行数等于字符串个数
        return string_count

# 主程序
def main():
    # 文件名
    filename = "strings.txt"
    
    # 生成并写入10个随机字符串到文件
    write_strings_to_file(filename, num_strings=10)
    
    # 读取文件并统计字符串的个数
    string_count = count_strings_in_file(filename)
    
    # 输出统计结果
    print(f"文件中字符串的个数是: {string_count}")

if __name__ == "__main__":
    main()
