# 分子動力学法(2) 温度制御と圧力制御

## 温度とは何か

我々は普段「温度」という言葉を何気なく使っている。気温が高ければ「今日は暑いな。26～27度くらいかな」と思うし、お風呂にはいって「ぬるいな、40度くらいかな」と思うであろう。また、日に照らされた鉄をうっかり触って「熱い！」と思うこともあるだろう。この時、我々は、気体、液体、固体の全てに共通して「温度」という量があることを無意識に仮定している。しかし、よく考えてみると温度という概念は不思議だ。我々はどうして温度というものがあると信じられるのか。また、どうやってそれを数値化しているのであろうか。

まず、小学校の理科で習ったガラス温度計は、ガラス管の中に色付きの液体が入っており、温度による膨張により体積変化するのを読み取ることで現在の温度を調べている。また、体温などを測るデジタル体温計は、サーミスタという温度変化にたいして電気抵抗変化が大きい物質が使われている。外で見かけるアナログ形式の気温計は、バイメタル方式であることが多い。これは温度により膨張率の異なる金属を貼り合わせることで、温度によって「反り」が変わることから温度を読み取るものだ。また、異なる金属の線を接続して両端に温度差を与えた時に電圧が生じることを利用した熱電対という温度計も、応答が早いことから実験用の温度計としてはよく用いられる。これらは温度変化に対して、物質の体積、電気抵抗、起電力の変化が起きることを利用して温度を数値化している。これらは相対的な温度変化はわかっても、温度の値はわからないため、基準となる温度(たとえば摂氏0度や摂氏100度)を用いて温度を較正することで温度計として使えるようにしている。

では、数値シミュレーションにおいて温度はどうやって測れば良いのだろうか？基準となる温度などを作ることができるのだろうか？温度計を作ったとして、温度の較正はできるのだろうか？

以下では、分子動力学シミュレーションにおける物理量、特に温度と圧力の定義について触れ、さらにその制御法について紹介する。

## 熱力学量の示量性と示強性

## 数値計算における変数と観測量

## 温度

### 温度の定義

## 圧力

### 圧力の定義

### Irvin-Kirkwoodゲージ

