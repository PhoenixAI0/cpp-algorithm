nums=()
nums+=200000
for i in {1..200001}
do
  nums+=($(( RANDOM )))
done
echo "${nums[@]}" > input.txt
