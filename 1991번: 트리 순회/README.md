# 1991번: 트리 순회 - <img src="https://static.solved.ac/tier_small/10.svg" style="height:20px" /> Silver I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/1991)

<p>이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.</p>

<p style="text-align: center;"><img alt="" src="/JudgeOnline/upload/201007/trtr.png" style="height:220px; width:265px"></p>

<p>예를 들어 위와 같은 이진 트리가 입력되면,</p>

<ul>
<li>전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)</li>
<li>중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)</li>
<li>후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)</li>
</ul>

<p>가 된다.</p>

## 입력

<p>첫째 줄에는 이진 트리의 노드의 개수 N(1 ≤ N ≤ 26)이 주어진다. 둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다. 노드의 이름은 A부터 차례대로 알파벳 대문자로 매겨지며, 항상 A가 루트 노드가 된다. 자식 노드가 없는 경우에는 .으로 표현한다.</p>

## 출력

<p>첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다. 각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.</p>

## 소스코드

[소스코드 보기](트리%20순회.cpp)