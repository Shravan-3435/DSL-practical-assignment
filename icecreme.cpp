#include&lt;iostream&gt;
using namespace std;
struct SLLNode* createSLL(int cnt, struct SLLNode *head);
void displaySLL(struct SLLNode *head);

void A_U_B();
void A_int_B();
void A_Min_B();
void B_Min_A();
void U_Min_A_U_B();

struct SLLNode
{
char data;
struct SLLNode *next;
}*headU, *headA, *headB;

int main()
{
int i,no;
cout&lt;&lt;&quot;\n\n\t How many Linked Lists: &quot;;
cin&gt;&gt;no;
headU = headA = headB = NULL;
for(i=1; i&lt;=no; i++)
{

if(i == 1)
{
cout&lt;&lt;&quot;\n\n\t Enter 10 Students of SE Comp : &quot;;
headU = createSLL(10, headU);
cout&lt;&lt;&quot;\n&quot;;
displaySLL(headU);
}

if(i == 2)
{
cout&lt;&lt;&quot;\n\n\t Enter 5 Students who like Vanilla Icecreme:&quot;;
headA = createSLL(5, headA);
cout&lt;&lt;&quot;\n&quot;;
displaySLL(headA);
}

if(i == 3)
{
cout&lt;&lt;&quot;\n\n\t Enter 5 Students who like Butterscotch Icecreme: &quot;;
headB = createSLL(5, headB);
cout&lt;&lt;&quot;\n&quot;;
displaySLL(headB);
}
}

cout&lt;&lt;&quot;\n\n Input Sets:------------------------&quot;;
cout&lt;&lt;&quot;\n\n Set &#39;U&#39;: &quot;;
displaySLL(headU);
cout&lt;&lt;&quot;\n\n Set &#39;A&#39;: &quot;;
displaySLL(headA);
cout&lt;&lt;&quot;\n\n Set &#39;B&#39;: &quot;;
displaySLL(headB);
cout&lt;&lt;&quot;\n\n Output Sets:------------------------&quot;;
A_U_B();
A_int_B();
A_Min_B();
B_Min_A();
U_Min_A_U_B();
cout&lt;&lt;&quot;\n\n&quot;;
return 0;
}
//.........................................................Function to create Linked List as Sets.

struct SLLNode* createSLL(int cnt, struct SLLNode *head)
{
int i;
struct SLLNode *p, *newNode;

for(i=0; i&lt;cnt; i++)

{
newNode = new(struct SLLNode); // 1. DMA

cout&lt;&lt;&quot;\n\t Enter Student Initial: &quot;; // 2. Data &amp; Address Assignment
cin&gt;&gt;newNode-&gt;data;
newNode-&gt;next = NULL;

if(head == NULL) // 3. Add node in the list
{
head = newNode;
p = head;
}
else
{
p-&gt;next = newNode;
p = p-&gt;next;
}
}

return head;
}
//...............................................Function to display Linked Lists as Sets.

void displaySLL(struct SLLNode *head)
{

struct SLLNode *p;

p = head;
while(p != NULL)
{
cout&lt;&lt;&quot; &quot;&lt;&lt;p-&gt;data;
p = p-&gt;next;
}
}

//................................................Function for Set A U B .
void A_U_B()
{
int i,j;
char a[10];
struct SLLNode *p, *q;
i = 0; //Index of Resultant Array
p = headA; //pointer to Set &#39;A&#39;
q = headB; //pointer to Set &#39;B&#39;

while(p != NULL &amp;&amp; q != NULL)
{
if(p-&gt;data == q-&gt;data)
{
a[i] = p-&gt;data;

i++;
p = p-&gt;next;
q = q-&gt;next;
}
else
{
a[i] = p-&gt;data;
i++;
p = p-&gt;next;
}
}
if(p == NULL) //Set &#39;A&#39; copied completely
{
while(q != NULL) //Copy remaining elements of Set &#39;B&#39;
{
a[i] = q-&gt;data;
i++;
q = q-&gt;next;
}
}

if(q == NULL) //Set &#39;B&#39; copied completely
{
while(p != NULL) //Copy remaining elements of Set &#39;A&#39;
{

a[i] = p-&gt;data;
i++;
p = p-&gt;next;
}
}

cout&lt;&lt;&quot;\n\n\t Set A U B: &quot;;
for(j=0; j &lt; i; j++)
cout&lt;&lt;&quot; &quot;&lt;&lt;a[j];

}

//................................................Function for Set A ^ B .

void A_int_B()
{
int i,j;
char a[10];
struct SLLNode *p, *q;

i = 0; //Index of Resultant Array
p = headA; //pointer to Set &#39;A&#39;

while(p != NULL)
{

q = headB; //pointer to Set &#39;B&#39;
while(q != NULL)
{
if(p-&gt;data == q-&gt;data)
{
a[i] = p-&gt;data;
i++;
}
q = q-&gt;next;
}
p = p-&gt;next;
}

cout&lt;&lt;&quot;\n\n\t Set A ^ B: &quot;;
for(j=0; j &lt; i; j++)
cout&lt;&lt;&quot; &quot;&lt;&lt;a[j];
}

//................................................Function for Set A - B .

void A_Min_B()
{
int i,j,flag;
char a[10];
struct SLLNode *p, *q;

i = 0; //Index of Resultant Array
p = headA; //pointer to Set &#39;A&#39;

while(p != NULL)
{
flag = 0;
q = headB; //pointer to Set &#39;B&#39;
while(q != NULL)
{
if(p-&gt;data == q-&gt;data)
{
flag = 1;
}
q = q-&gt;next;
}
if(flag == 0)
{
a[i] = p-&gt;data;
i++;
}
p = p-&gt;next;
}

cout&lt;&lt;&quot;\n\n\t Set A - B: &quot;;

for(j=0; j &lt; i; j++)
cout&lt;&lt;&quot; &quot;&lt;&lt;a[j];
}
//................................................Function for Set B - A.

void B_Min_A()
{
int i,j,flag;
char a[10];
struct SLLNode *p, *q;

i = 0; //Index of Resultant Array
q = headB; //pointer to Set &#39;B&#39;
while(q != NULL)
{
flag = 0;
p = headA; //pointer to Set &#39;A&#39;
while(p != NULL)
{
if(q-&gt;data == p-&gt;data)
{
flag = 1;
}
p = p-&gt;next;
}

if(flag == 0)
{
a[i] = q-&gt;data;
i++;
}
q = q-&gt;next;
}

cout&lt;&lt;&quot;\n\n\t Set B - A: &quot;;
for(j=0; j &lt; i; j++)
cout&lt;&lt;&quot; &quot;&lt;&lt;a[j];
}
//................................................Function for Set U - (A U B).

void U_Min_A_U_B()
{
int i,j,flag;
char a[10];
struct SLLNode *p, *q, *r;

i = 0; //Index of Resultant Array
p = headU; //pointer to Set &#39;U&#39;

while(p != NULL)
{

flag = 0;
q = headA; //pointer to Set &#39;A&#39;
r = headB; //pointer to Set &#39;B&#39;
while(q != NULL)
{
if(p-&gt;data == q-&gt;data)
{
flag = 1;
}
q = q-&gt;next;
}
while(r != NULL)
{
if(p-&gt;data == r-&gt;data)
{
flag = 1;
}
r = r-&gt;next;
}
if(flag == 0)
{
a[i] = p-&gt;data;
i++;
}
p = p-&gt;next;

}

cout&lt;&lt;&quot;\n\n\t Set U - (A U B): &quot;;
for(j=0; j &lt; i; j++)
cout&lt;&lt;&quot; &quot;&lt;&lt;a[j];
}