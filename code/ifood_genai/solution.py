# Você pode criar outros arquivos e organizar o código como preferir,
# mas a função validate_and_normalize deve continuar neste arquivo.
from typing import Any
import math

def age_validation(age: Any) -> str | None:
  if age is None: 
    return "null"

  if type(age) is not int:
    return "invalid_type"

  if age < 0 or age > 120:
    return "out_of_range" 

  return None

def income_validation(income: Any, age: Any) -> str | None: 
  if income is None: 
    return "null"

  if type(income) not in (int, float):
    return "invalid_type"

  if type(income) is float and not math.isfinite(income):
    return "not_finite"

  if income < 0:
    return "out_of_range"

  if (type(age) is int and 0 <= age <= 120):
    if age < 16 and income != 0:
      return "inconsistent"

  return None

def country_validation(country: Any) -> str | None:
  if country is None:
    return "null"
  
  if type(country) is not str:
    return "invalid_type"

  if country.strip() == "":
    return "empty"

  return None 

def validate_and_normalize(request: Any) -> dict[str, Any]:
    """Valida e normaliza uma requisição conforme as regras do enunciado."""

    valid_request = isinstance(request, dict)

    if not valid_request:
      return {
        "ok": False,
        "request_id": None,
        "errors": [
          {"field": "request", "code": "invalid_type"}
        ]
      }

    request_id = request.get("request_id")
    

    if "features" not in request:
      return {
        "ok": False,
        "request_id": request_id,
        "errors": [{"field": "features", "code": "missing"}]
      }

    features = request["features"]
    
    if features is None: 
      return {
        "ok": False,
        "request_id": request_id,
        "errors": [
          {"field": "features", "code": "null"}
        ]
      }

    if not isinstance(features, dict): 
      return {
        "ok": False,
        "request_id": request_id,
        "errors": [
          {"field": "features", "code": "invalid_type"}
        ]
      }

    errors = []

    age = features.get("age")

    if "age" not in features: 
      errors.append({
        "field": "features.age",
        "code": "missing"
      })
    else: 
      age_error = age_validation(age)

      if age_error is not None:
        errors.append({
          "field": "features.age", 
          "code": age_error
        })


    income = features.get("income")

    if "income" not in features:
      errors.append({
        "field": "features.income",
        "code": "missing"
      })
    else:
      income_error = income_validation(income, age)

      if income_error is not None:
        errors.append({
          "field": "features.income",
          "code": income_error
        })

    country = features.get("country")

    if "country" not in features:
      errors.append({
        "field": "features.country",
        "code": "missing"
      })
    else:
      country_error = country_validation(country)

      if country_error is not None:
        errors.append({
          "field": "features.country",
          "code": country_error
        })
    
    for key in features:
      needed_features = ["age", "income", "country"]
      if key not in needed_features:
        errors.append({
          "field": f"features.{key}",
          "code": "unknown_field"
        })

    if errors:
      return {
        "ok": False, 
        "request_id": request_id,
        "errors": errors
      }

    normalized_country = country.strip().upper()

    return {
      "ok": True,
      "request_id": request_id,
      "value": {"age": age, "income": income, "country": normalized_country}
    }