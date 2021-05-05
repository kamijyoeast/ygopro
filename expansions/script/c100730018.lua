--高速决斗技能-你被捕了！
Duel.LoadScript("speed_duel_common.lua")
function c100730018.initial_effect(c)
	--activate
	local e1=Effect.GlobalEffect()
	e1:SetType(EFFECT_TYPE_FIELD+EFFECT_TYPE_CONTINUOUS)
	e1:SetCode(EVENT_PREDRAW)
	e1:SetOperation(c100730018.skill)
	e1:SetLabelObject(c)
	Duel.RegisterEffect(e1,0)
	aux.RegisterSpeedDuelSkillCardCommon()
end

function c100730018.skill(e,tp,eg,ep,ev,re,r,rp)
	tp = e:GetLabelObject():GetOwner()
	local g=Group.CreateGroup()
	local c=Duel.CreateToken(tp,7391448)
	g:AddCard(c)
	aux.CardAddedBySkill:AddCard(c)
	c=Duel.CreateToken(tp,58901502)
	g:AddCard(c)
	aux.CardAddedBySkill:AddCard(c)
	c=Duel.CreateToken(tp,63364266)
	g:AddCard(c)
	aux.CardAddedBySkill:AddCard(c)
	c=Duel.CreateToken(tp,84305651)
	g:AddCard(c)
	aux.CardAddedBySkill:AddCard(c)
	c=Duel.CreateToken(tp,98637386)
	g:AddCard(c)
	aux.CardAddedBySkill:AddCard(c)
	Duel.SendtoDeck(g,nil,-1,REASON_RULE)
	local g2=g:RandomSelect(tp,3)
	Duel.Exile(g2,REASON_RULE)
	Duel.Hint(HINT_CARD,1-tp,100730018)
	local d=Duel.CreateToken(tp,11429811)
	Duel.SSet(tp,d)
	e:Reset()
end
