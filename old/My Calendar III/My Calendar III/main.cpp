//
//  main.cpp
//  My Calendar III
//
//  Created by liang on 14/10/18.
//  Copyright © 2018年 liang. All rights reserved.
//  https://leetcode.com/problems/my-calendar-iii/
/**
 Implement a MyCalendarThree class to store your events. A new event can always be added.
 
 Your class will have one method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.
 
 A K-booking happens when K events have some non-empty intersection (ie., there is some time that is common to all K events.)
 
 For each call to the method MyCalendar.book, return an integer K representing the largest integer such that there exists a K-booking in the calendar.
 
 Your class will be called like this: MyCalendarThree cal = new MyCalendarThree(); MyCalendarThree.book(start, end)
 Example 1:
 
 MyCalendarThree();
 MyCalendarThree.book(10, 20); // returns 1
 MyCalendarThree.book(50, 60); // returns 1
 MyCalendarThree.book(10, 40); // returns 2
 MyCalendarThree.book(5, 15); // returns 3
 MyCalendarThree.book(5, 10); // returns 3
 MyCalendarThree.book(25, 55); // returns 3
 Explanation:
 The first two events can be booked and are disjoint, so the maximum K-booking is a 1-booking.
 The third event [10, 40) intersects the first event, and the maximum K-booking is a 2-booking.
 The remaining events cause the maximum K-booking to be only a 3-booking.
 Note that the last event locally causes a 2-booking, but the answer is still 3 because
 eg. [10, 20), [10, 40), and [5, 15) are still triple booked.
 
 
 Note:
 
 The number of calls to MyCalendarThree.book per test case will be at most 400.
 In calls to MyCalendarThree.book(start, end), start and end are integers in the range [0, 10^9].
 */

#include <iostream>
#include <vector>

using namespace std;

class MyCalendarThree {
public:
    MyCalendarThree() {
        KBooking = 0;
        root = new Node();
    }
    
    ~MyCalendarThree() {
        if (root) {
            delete root;
            root = nullptr;
        }
    }
    
    int book(int start, int end) {
        traverseTree(root, 0, N, start, end - 1);
        return KBooking;
    }
    
private:
    class Node {
    public:
        Node() {
            leftChild = nullptr;
            rightChild = nullptr;
            left = 0;
            right = 0;
            count = 0;
            max = 0;
            updated = false;
        }
        ~Node() {
            if (leftChild != nullptr) {
                delete leftChild;
                leftChild = nullptr;
            }
            
            if (rightChild != nullptr) {
                delete rightChild;
                rightChild = nullptr;
            }
        }
        
        int64_t left;
        int64_t right;
        int count;
        int max;
        bool updated;
        
        Node *leftChild;
        Node *rightChild;
    };
    
    Node *root;
    int64_t N = 1e9 + 1;
    int KBooking;
    
    void traverseTree(Node *node, int64_t left, int64_t right, int64_t start, int64_t end) {
        if (node == nullptr || start > end) {
            return;
        }
        
        // 减少不必要的子节点的创建
        // 只在当前节点不是正好覆盖区间时，才创建子节点。
        bool isCover = false;
        if (left == start && end == right) {
            isCover = true;
            node->count++;
            if (node->count > KBooking) {
                KBooking = node->count;
            }
        }
        
        if (left >= right) {
            return;
        }
        
        int64_t mid = left + (right - left) / 2;
        if (mid >= end) {
            if (node->leftChild == nullptr && !isCover) {
                node->leftChild = new Node();
                node->leftChild->count = node->count;
                node->leftChild->left = left;
                node->leftChild->right = mid;
            }
            if (node->leftChild) {
                traverseTree(node->leftChild, left, mid, start, end);
            }
        } else if (mid < start) {
            if (node->rightChild == nullptr && !isCover) {
                node->rightChild = new Node();
                node->rightChild->count = node->count;
                node->rightChild->left = mid + 1;
                node->rightChild->right = right;
            }
            if (node->rightChild) {
                traverseTree(node->rightChild, mid + 1, right, start, end);
            }
        } else {
            if (node->leftChild == nullptr && !isCover) {
                node->leftChild = new Node();
                node->leftChild->count = node->count;
                node->leftChild->left = left;
                node->leftChild->right = mid;
            }
            if (node->leftChild) {
                traverseTree(node->leftChild, left, mid, start, mid);
            }
            
            if (node->rightChild == nullptr && !isCover) {
                node->rightChild = new Node();
                node->rightChild->count = node->count;
                node->rightChild->left = mid + 1;
                node->rightChild->right = right;
            }
            if (node->rightChild) {
                traverseTree(node->rightChild, mid + 1, right, mid + 1, end);
            }
        }
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */

/**
 ["MyCalendarThree","book","book","book","book","book","book"]
 [[],[10,20],[50,60],[10,40],[5,15],[5,10],[25,55]]
 [null,1,1,2,3,3,3]
 */
void test1() {
    MyCalendarThree *obj = new MyCalendarThree();
    int ret = 0;
    ret = obj->book(10, 20); // returns 1
    printf("%d ", ret);
    ret = obj->book(50, 60); // returns 1
    printf("%d ", ret);
    ret = obj->book(10, 40); // returns 2
    printf("%d ", ret);
    ret = obj->book(5, 15); // returns 3
    printf("%d ", ret);
    ret = obj->book(5, 10); // returns 3
    printf("%d ", ret);
    ret = obj->book(25, 55); // returns 3
    printf("%d ", ret);
    printf("\n");
}

/**
 ["MyCalendarThree","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book"]
 [[],[26,45],[76,92],[25,37],[18,36],[40,50],[19,31],[48,60],[1,16],[46,65],[61,78],[74,90],[43,60],[27,43],[5,21],[80,90],[14,29],[3,19],[3,14],[75,89],[56,69]]
 
 [null,1,1,2,3,3,4,4,4,4,4,4,4,5,5,5,6,6,6,6,6]
 */

void test2() {
    MyCalendarThree *obj = new MyCalendarThree();
    int ret = 0;
    ret = obj->book(26, 45);
    printf("%d ", ret);
    ret = obj->book(76, 92);
    printf("%d ", ret);
    ret = obj->book(25, 37);
    printf("%d ", ret);
    ret = obj->book(18, 36);
    printf("%d ", ret);
    ret = obj->book(40, 50);
    printf("%d ", ret);
    ret = obj->book(19, 31);
    printf("%d ", ret);
    ret = obj->book(48, 60);
    printf("%d ", ret);
    ret = obj->book(1, 16);
    printf("%d ", ret);
    ret = obj->book(46, 65);
    printf("%d ", ret);
    ret = obj->book(61, 78);
    printf("%d ", ret);
    ret = obj->book(74, 90);
    printf("%d ", ret);
    ret = obj->book(43, 60);
    printf("%d ", ret);
    ret = obj->book(27, 43);
    printf("%d ", ret);
    ret = obj->book(5, 21);
    printf("%d ", ret);
    ret = obj->book(80, 90);
    printf("%d ", ret);
    ret = obj->book(14, 29);
    printf("%d ", ret);
    ret = obj->book(3, 19);
    printf("%d ", ret);
    ret = obj->book(3, 14);
    printf("%d ", ret);
    ret = obj->book(75, 89);
    printf("%d ", ret);
    ret = obj->book(56, 69);
    printf("%d ", ret);
    printf("\n");
}

/**
 
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    test1();
    test2();
    return 0;
}

/**
 ["MyCalendarThree","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book"]
 [[],[712153,844116],[852393,1000000],[113731,287834],[509695,634936],[761803,874394],[122398,267208],[69162,180130],[748228,888186],[875961,1000000],[404722,507887],[633819,826080],[14289,180854],[955538,1000000],[378113,496848],[543660,651012],[181132,290675],[956102,1000000],[957257,1000000],[600667,747779],[278331,469959],[566194,696172],[883959,1000000],[715616,816575],[193943,375574],[280703,443000],[3337,200742],[143688,298390],[976625,1000000],[344574,544313],[572234,699015],[784855,909483],[221295,339380],[638165,808213],[327267,474505],[674915,793515],[408545,572360],[943939,1000000],[617154,739880],[752183,936158],[720794,848557]]
 */
/** ["MyCalendarThree","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book","book"]
 [[],[38115,42136],[958404,966280],[843000,850441],[419867,425511],[737800,744230],[513787,519408],[408938,413517],[143881,149835],[140857,148801],[37665,44486],[263519,269131],[904640,910087],[574705,579510],[722387,729157],[834002,838105],[394555,398606],[399830,407030],[837124,843094],[794874,801773],[383305,387366],[490598,498193],[132690,137344],[941531,947919],[606101,613674],[262693,269135],[516481,524337],[996011,1000000],[152493,157071],[295535,303408],[33541,39014],[395328,400086],[410084,414159],[797985,803038],[516619,523116],[253508,261221],[645119,650049],[477374,483834],[500074,505454],[30837,37723],[814231,820873],[172845,179510],[205981,213882],[787030,792875],[61920,69883],[150496,157505],[384357,391167],[721369,725590],[534369,539516],[280045,284263],[210280,217278],[537114,543785],[466714,472275],[718128,722688],[987800,994261],[403558,407893],[296350,303196],[831814,836824],[237903,243507],[935549,942779],[445224,450667],[915618,920265],[740325,746863],[463324,468759],[27223,32773],[235532,239678],[484348,488574],[167439,174149],[852607,860111],[793227,798884],[351458,357905],[815256,821302],[343417,350313],[933092,938145],[433338,440515],[631264,637911],[80855,88571],[853413,858820],[79018,86947],[172155,179154],[430418,436564],[895501,902174],[865775,871764],[137738,145700],[260248,267031],[243117,248720],[589323,593522],[925712,931467],[737971,742599],[300575,306348],[708311,712679],[825011,832594],[891275,898658],[430816,435017],[383892,390670],[521952,526686],[111249,118725],[970493,976603],[840423,844439],[222873,229740],[378625,382648],[69349,74754],[405874,413208],[319662,326856],[157125,161893],[903154,909030],[223760,229050],[432737,438015],[857337,865266],[302015,309497],[474626,479474],[902751,907120],[472790,478058],[838371,842477],[568291,572851],[861025,868835],[57284,63032],[429522,436795],[44967,52944],[547448,554477],[475430,481877],[605571,612392],[544438,550192],[990528,996760],[55017,59976],[837404,844423],[991045,998944],[311358,318315],[950638,957808],[867222,874924],[844444,851107],[287054,294864],[799374,805776],[863904,871740],[105491,110401],[716934,723594],[155104,161948],[379876,386373],[765526,772872],[191934,196719],[102866,109505],[790004,794066],[751334,757170],[583846,591317],[503328,509042],[166649,172292],[8698,15047],[256513,263640],[648162,653780],[233769,239518],[523589,528481],[731350,735533],[672532,678708],[576431,582209],[755656,759692],[974807,979402],[995348,999631],[492392,498752],[948816,956133],[26559,32230],[19690,23991],[531641,537510],[597060,602481],[79990,86760],[341363,346096],[469098,474407],[220829,226740],[972936,980408],[313607,320729],[598707,604952],[618054,622342],[521745,526224],[28198,34529],[203082,208967],[756102,760212],[992091,998506],[227305,232445],[236077,243952],[393811,400856],[578122,582782],[201286,209275],[136968,142955],[420557,426345],[994351,998734],[634621,640368],[519742,525643],[670284,677772],[473967,478201],[632205,639653],[147083,154613],[75938,80263],[272508,277639],[752402,756449],[490729,498411],[926727,932072],[692723,698141],[587755,594466],[664900,669584],[54930,59371],[961550,967124],[501867,507518],[603909,610459],[574220,579676],[428017,435627],[587095,592646],[657624,661802],[320479,325807],[939720,946056],[253754,260276],[1417,6497],[594629,600018],[528820,534861],[850134,857002],[486250,491745],[558442,562771],[577895,585468],[52568,58177],[843178,850984],[904127,908396],[676130,682096],[579515,586608],[79212,84546],[202370,209885],[29555,37017],[695502,700963],[296003,302598],[397491,405206],[212513,216826],[741217,745507],[175541,179575],[916115,922846],[342050,346158],[107334,111472],[340795,348431],[440923,447843],[717089,721720],[520327,525613],[973680,980795],[990497,994978],[239228,243847],[547345,551728],[456776,464333],[793256,798825],[750591,756326],[340761,347427],[78836,83939],[273218,280452],[606596,614042],[342896,348516],[617167,624306],[46446,52414],[688095,693591],[723617,729075],[815208,822917],[540404,547924],[676730,683063],[256974,263019],[651977,658505],[905598,913525],[863131,869581],[862935,868033],[726199,732065],[251311,257734],[68586,75847],[928509,936029],[836470,844456],[890655,897064],[153848,158415],[678339,685417],[762921,767971],[666454,671985],[934292,940927],[257821,264608],[689120,695405],[79124,84263],[421436,425759],[577079,582213],[358015,364507],[554989,559394],[541515,545682],[761539,766319],[936149,943260],[58936,63250],[218479,225436],[934204,939420],[528948,535226],[244508,250415],[841498,847774],[504454,511520],[303976,311325],[173124,177521],[293575,299515],[717691,723645],[43574,50720],[221503,226601],[642137,648038],[168556,174293],[144435,149936],[925261,929567],[828307,832441],[641483,647381],[999547,1000000],[208965,215952],[538588,543481],[649849,656248],[169449,175404],[941118,946005],[640166,645490],[904044,909104],[797075,802508],[180994,185267],[801605,808464],[841946,847449],[890595,897276],[519712,526494],[607017,614472],[998916,1000000],[284238,290479],[94883,99146],[125053,131866],[636199,641443],[778577,785438],[347627,355015],[154895,161186],[696677,703319],[677563,685440],[968518,975516],[989152,995070],[599851,606687],[857212,862328],[967896,973979],[447556,452921],[337502,342859],[220535,224639],[388862,393535],[667830,673231],[331741,337543],[802492,808630],[464735,470141],[147861,152599],[86003,92271],[433512,438866],[165237,171517],[919990,925706],[21621,28794],[613399,620633],[285995,292185],[377504,385166],[378467,384946],[109655,114679],[503463,508601],[525151,529376],[594018,601315],[121351,128754],[403040,407116],[834511,839658],[333513,337937],[468938,476691],[378971,383769],[382612,386657],[268535,274190],[634992,640392],[956948,964099],[959381,965592],[290196,296126],[877298,882241],[816863,823474],[651841,658171],[56861,64386],[931927,938309],[774670,781124],[680856,686635],[23121,27121],[757063,764599],[343431,348933],[466726,471244],[78025,84393],[178042,182878],[741630,749443],[726319,732471],[524326,530107],[223594,229238],[592955,600139],[19907,25380],[431196,438834],[648191,654266],[254976,262567],[987159,994785],[157709,162664],[986222,992732],[486803,494401],[124972,129778],[680329,686553],[782674,787594],[586301,593659],[136114,142693],[77362,83729],[134947,140777],[585496,591789],[53367,57914]]
 */
