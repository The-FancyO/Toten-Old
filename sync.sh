git add .

echo "Input git message: "
read message -a

git commit -m $message
git pull
