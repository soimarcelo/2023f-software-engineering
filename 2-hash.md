# 2-hash.md
## 説明
- ランダムな百万件のデータをハッシュテーブルに格納します
- 衝突はlinear probingで回避しました
- 最後のランダムなデータを3件検索して挙動を確認しました
## 入出力
[Running] cd "/Users/soimarcelo/Projects/2023f-software-engineering/" && gcc 2-hash.c -o 2-hash && "/Users/soimarcelo/Projects/2023f-software-engineering/"2-hash
Key: 1, Value: 20
Key: 2, Value: 70
Key: 42, Value: 80

[Done] exited with code=0 in 0.981 seconds

