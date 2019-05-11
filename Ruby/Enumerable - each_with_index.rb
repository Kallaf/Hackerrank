def skip_animals(animals, skip)
  animalsAfterSkip = []
  animals.each_with_index do |item, index|
          if(index >= skip)
              animalsAfterSkip.push("#{index}:#{item}")
          end
  end
    return animalsAfterSkip
end
