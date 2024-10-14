#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<iomanip>
int mode = 0; //确认模式，为1时为自动，为0时手动输入


// 篮球联赛，先实现单独的队伍
class Team
{
public:
    std::string name; //名称
    int points;      // 积分
    int goaldif;     // 净胜球
    int goalsum;    //进球数
    Team(const std::string &n1) : name(n1), points(0), goaldif(0), goalsum(0) {}   //init
    //虚函数，便于继承后重载
    virtual void update(int goal,int goalagainist)
    {
        if(goal>goalagainist)
        {
            points += 2;
            goaldif += goal - goalagainist;
            goalsum += goal;
        }
        else if(goal==goalagainist)
            std::cout << "error";
        else
        {
            points += 1;
            goaldif += goal - goalagainist;
            goalsum += goal;
        }
    }
};

//继承出篮球队
class BasketTeam:public Team
{
private:
    int win;   //胜场
    int sum;   //总场次
public:
    BasketTeam(const std::string &n1):Team::Team(n1),win(0),sum(0) {}    //init
    float shenglv() { float x = 0; if(sum!=0) x = (float)win/sum; return x; }      //获得init
    //虚函数重载
    virtual void update(int goal,int goalagainist)
    {
        if(goal>goalagainist)
        {
            ++win;      //胜场+1
            ++sum;      //总场+1
            points += 2;   //积分+2
            goaldif += goal - goalagainist;    //净胜球
            goalsum += goal;        //总进球
        }
        else if(goal==goalagainist)    
            std::cout << "error";
        else
        {
            ++sum;      //总场次+1
            points += 1;    //积分+1
            goaldif += goal - goalagainist;    //净胜球
            goalsum += goal;
        }
    }
    std::string Get()
    {
        return std::to_string(win) + "/" + std::to_string(sum);    //得到胜场的字符串显示（类似分数显示）
    }
        //重载 ！=  便于利用
    bool operator!= (const BasketTeam& n1)
    {
        if(name!=n1.name)
            return true;
        else
            return false;
    }
};

// 实现联赛功能
class League 
{
private:
    std::vector<BasketTeam> dispaly;     //显示，进行联赛的轮
    std::vector<BasketTeam> teams;       // 存储显示的信息
    int times=0;     //轮数
public:
    void add(const BasketTeam &team) { teams.push_back(team);dispaly.push_back(team);}   //init

    //进行比赛
    void playgame(BasketTeam &t1,BasketTeam &t2,int goal1=0,int goal2=0)     
    {
        auto it1 = teams.begin();
        auto it2 = teams.begin();
        for (; *it1 != t1;it1++)
        {}
        for (; *it2 != t2;it2++)
        {}
        it1->update(goal1, goal2);
        it2->update(goal2, goal1);
        times++;
    }
    // 自动比赛
    void atuopaly();
    //显示比赛信息
    void displayStandings();
};
//实现随机数的功能
int ramdon(int *goal1,int *goal2)
{ 
        int min = 60,max = 150;
        std::random_device seed;//硬件生成随机数种子
	    std::ranlux48 engine(seed());//利用种子生成随机数引擎
        std::uniform_int_distribution<> distrib(min, max);//设置随机数范围，并为均匀分布
        *goal1 = distrib(engine);//随机数
        *goal2 = *goal1;
        while (*goal1 == *goal2)
        {
            std::random_device seed2;
            std::ranlux48 engine(seed2());
            *goal2 = distrib(engine);
        }
}
//实现自动比赛的功能
void League::atuopaly()
{
    
        for (auto iter1= dispaly.begin(); iter1 != dispaly.end(); iter1++)
        {
            for (auto iter2 = dispaly.begin(); iter2 != dispaly.end(); iter2++)
            {
                if(iter1==iter2)
                    continue;
                else
                {
                    int goal1, goal2;
                    char x;
                    ramdon(&goal1, &goal2);
                    playgame(*iter1, *iter2, goal1, goal2);
                    displayStandings();
                    std::cout << "\ncontinue?(if you want to contiue ,please press y):  ";
                    std::cin >> x;
                    if(x=='y')
                        {}
                    else
                        break;
                }
            }
        }
        std::cout << "All game is over!";
}
//实现输出比赛结果的功能
void League::displayStandings() 
{
        // 使用STL中的sott算法进行排序
        std::sort(teams.begin(), teams.end(), []( BasketTeam& a, BasketTeam& b) {
            if (a.shenglv() != b.shenglv()) {
                return a.shenglv() > b.shenglv();
            } else if (a.goaldif != b.goaldif) {
                return a.goaldif > b.goaldif;
            } else {
                return a.goalsum > b.goalsum;
            }
        });
        // 显示排名
        std::cout<<"\n\n\n"<<times<<" round:\n"<< "Team \t    Winning Percentage \t Point Differential \t   Points For \t points\n";
        for (auto& team : teams) {
            std::cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(2);   //输出两位小数
            std::cout <<std::left << std::setw(8)<< team.name << "\t" << std::left << std::setw(10) << team.shenglv() <<team.Get()
            <<"\t\t"<< std::left << std::setw(8) << team.goaldif << "\t\t" 
            << std::left << std::setw(10)<< team.goalsum << std::left << std::setw(3)<<team.points<<"\n";
        }
}
// 主函数
int main(void)
{
    League cba;
    BasketTeam team0("xinjiang");
    BasketTeam team1("jiangxi");
    BasketTeam team2("zhejiang");
    BasketTeam team3("anhui");
    BasketTeam team4("beijing");
    cba.add(team0);
    cba.add(team1);
    cba.add(team2);
    cba.add(team3);
    cba.add(team4);
    std::cout << "atuo?(if you want to auto,please press 1)";
    std::cin >> mode;
    if(mode==1)
        cba.atuopaly();
    else
        {
            //自行添加
            cba.playgame(team1, team0, 100, 99);
            cba.playgame(team1, team2, 100, 90);
            cba.playgame(team1, team3, 120, 79);
            cba.playgame(team1, team4, 90, 89);
            cba.displayStandings();
        }
}