# 12222번: Allergy Testing (Small) - <img src="https://static.solved.ac/tier_small/21.svg" style="height:20px" /> Diamond V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12222)

<p>Kelly is allergic to exactly one of <strong>N</strong> foods, but she isn't sure which one. So she decides to undergo some experiments to find out.</p>

<p>In each experiment, Kelly picks several foods and eats them all. She waits <strong>A</strong> days to see if she gets any allergic reactions. If she doesn't, she knows she isn't allergic to any of the foods she ate. If she does get a reaction, she has to wait for it to go away: this takes a total of <strong>B</strong> days (measured from the moment when she ate the foods).</p>

<p>To simplify her experimentation, Kelly decides to wait until each experiment is finished (after <strong>A</strong> or <strong>B</strong> days) before starting the next one. At the start of each experiment, she can choose the set of foods she wants to eat based on the results of previous experiments.</p>

<p>Kelly chooses what foods to eat for each experiment to minimize the worst-case number of days before she knows which of the <strong>N</strong> foods she is allergic to. How long does it take her in the worst case?</p>

## 입력

<p>The first line of the input gives the number of test cases, <strong>T</strong>. <strong>T</strong> test cases follow. Each test case on a single line, containing three space-separated integers: <strong>N</strong>, <strong>A</strong> and <strong>B</strong>.</p>

<p>Limits</p>

<ul>
<li>1 ≤ <strong>T</strong> ≤ 200.</li>
<li><span style="line-height:1.6em">1 ≤ </span><strong style="line-height:1.6em">N</strong><span style="line-height:1.6em"> ≤ 10</span><sup style="line-height:1.6em">15</sup><span style="line-height:1.6em">.</span></li>
<li>1 ≤ <strong>A</strong> ≤ <strong>B</strong> ≤ 100.</li>
</ul>

## 출력

<p>For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and <strong>y</strong> is the number of days it will take for Kelly to find out which food she is allergic to, in the worst case.</p>

## 소스코드

[소스코드 보기](Allergy%20Testing%20(Small).cpp)